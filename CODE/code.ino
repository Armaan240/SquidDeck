#include <FastLED.h>
#include <Wire.h>
#define NUM_LEDS     24      
#define DATA_PIN     4       
#define FD_PIN       2       
#define BRIGHTNESS   20      
#define USE_24H      false   
#define NFC_ADDR     0x55

CRGB leds[NUM_LEDS];
long      timeOfDay = -1;        
unsigned long lastTick = 0;
bool      timeKnown = false;

bool      blinkOn = true;
unsigned long lastBlink = 0;

bool      fieldActive = false;       
unsigned long fieldAnimStart = 0;    

void setup() {
  Serial.begin(115200);
  delay(200);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear(true);

  pinMode(FD_PIN, INPUT_PULLUP);  
  Wire.begin();

  Serial.println();
  Serial.println(F("SquidCard NFC Clock ready."));
  Serial.println(F("Set time by sending  T HH:MM:SS   e.g.  T14:30:00"));

  nfcRecoverAddress();
  nfcReadInfo();

  nfcWriteHello();

  lastTick = millis();
}

void loop() {
  handleSerial();     
  advanceClock();     
  if (digitalRead(FD_PIN) == LOW) {        
    if (!fieldActive) { fieldActive = true; fieldAnimStart = millis(); }
    drawFieldAnimation();
  } else {
    fieldActive = false;
    drawClock();
  }

  FastLED.show();
}
void drawFieldAnimation() {
  FastLED.clear();

  unsigned long t = millis() - fieldAnimStart;
  int head = (int)((t / 20) % NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++) {
    int dist = (head - i + NUM_LEDS) % NUM_LEDS; 
    if (dist < 8) {
      uint8_t bright = 255 - (dist * 32);          
      leds[i] = CRGB(0, bright, bright);         
    }
  }
}

void handleSerial() {
  if (!Serial.available()) return;
  String s = Serial.readStringUntil('\n');
  s.trim();
  if (s.length() == 0) return;

  if (s.charAt(0) == 'T' || s.charAt(0) == 't') {
    int h = s.substring(1, 3).toInt();
    int m = s.substring(4, 6).toInt();
    int sec = s.substring(7, 9).toInt();
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && sec >= 0 && sec < 60) {
      timeOfDay = (long)h * 3600L + (long)m * 60L + sec;
      timeKnown = true;
      lastTick = millis();
      Serial.print(F("Time set to "));
      Serial.print(h); Serial.print(':');
      Serial.print(m); Serial.print(':');
      Serial.println(sec);
    } else {
      Serial.println(F("Bad time. Use T HH:MM:SS (24h)."));
    }
  } else if (s.charAt(0) == 'N' || s.charAt(0) == 'n') {
    nfcReadInfo();
  }
}

void advanceClock() {
  if (!timeKnown) return;
  unsigned long now = millis();
  if (now - lastTick >= 1000UL) {
    unsigned long secs = (now - lastTick) / 1000UL;
    lastTick += secs * 1000UL;
    timeOfDay = (timeOfDay + (long)secs) % 86400L;
  }
}

int ringPos(long value, long maxValue) {
  return (int)((value * NUM_LEDS) / maxValue) % NUM_LEDS;
}

void drawClock() {
  FastLED.clear();

  if (!timeKnown) {
    uint8_t b = (sin8(millis() / 8)) / 3;
    for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB(b, b / 2, 0);
    return;
  }

  long h = timeOfDay / 3600L;
  long m = (timeOfDay % 3600L) / 60L;
  long sec = timeOfDay % 60L;
  long hVal, hMax;
  if (USE_24H) { hVal = h; hMax = 24; }
  else         { hVal = h % 12; hMax = 12; }
  int hourPos = ringPos(hVal * 60L + m, hMax * 60L);  
  int minPos  = ringPos(m, 60);
  int secPos  = ringPos(sec, 60);
  if (millis() - lastBlink > 250) { blinkOn = !blinkOn; lastBlink = millis(); }
  if (blinkOn) leds[secPos] = CRGB(0, 0, 40);
  leds[minPos]  = CRGB::Green;
  leds[hourPos] = CRGB::Red;
}

void nfcReadInfo() {
  Serial.println(F("--- NFC chip check (I2C) ---"));

  Wire.beginTransmission(NFC_ADDR);
  byte err = Wire.endTransmission();
  if (err != 0) {
    Serial.print(F("No NFC chip at 0x55 (I2C error "));
    Serial.print(err);
    Serial.println(F("). Check wiring/level shifter/power."));
    return;
  }
  Serial.println(F("NFC chip found at 0x55."));

  byte block0[16];
  if (readBlock(0x00, block0)) {
    Serial.print(F("Block0: "));
    for (int i = 0; i < 16; i++) {
      if (block0[i] < 16) Serial.print('0');
      Serial.print(block0[i], HEX);
      Serial.print(' ');
    }
    Serial.println();
    Serial.print(F("UID0 (should be 04 for NXP): 0x"));
    Serial.println(block0[0], HEX);
  } else {
    Serial.println(F("Could not read block 0."));
  }
  Serial.println(F("----------------------------"));
}

void nfcRecoverAddress() {
  byte foundAddr = 0;
  Wire.beginTransmission(0x55);
  if (Wire.endTransmission() == 0) { foundAddr = 0x55; }
  else {
    
    Wire.beginTransmission(0x02);
    if (Wire.endTransmission() == 0) { foundAddr = 0x02; }
  }

  if (foundAddr == 0) {
    Serial.println(F("Address recovery: chip not found at 0x55 or 0x02."));
    return;
  }
  if (foundAddr == 0x55) {
    Serial.println(F("Address OK (0x55)."));
    return;
  }

  Serial.println(F("Chip at 0x02 - restoring to 0x55..."));
  byte b0[16];

  Wire.beginTransmission(0x02);
  Wire.write(0x00);
  if (Wire.endTransmission(false) != 0) { Serial.println(F("recover read fail")); return; }
  if (Wire.requestFrom(0x02, 16) != 16) { Serial.println(F("recover read fail")); return; }
  for (int i = 0; i < 16; i++) b0[i] = Wire.read();

  b0[0] = 0xAA;   

  Wire.beginTransmission(0x02);
  Wire.write(0x00);
  for (int i = 0; i < 16; i++) Wire.write(b0[i]);
  if (Wire.endTransmission() == 0) {
    delay(10);
    Serial.println(F("Address restored to 0x55. (power-cycle if needed)"));
  } else {
    Serial.println(F("recover write fail"));
  }
}


void nfcWriteHello() {
  const char* TEXT = "hello";
  uint8_t textLen = 5;                 

 
  uint8_t payloadLen = 3 + textLen;    
  uint8_t ndefLen    = 4 + payloadLen; 
  uint8_t data[16] = {0};
  uint8_t i = 0;
  data[i++] = 0x03;       
  data[i++] = ndefLen;     
  data[i++] = 0xD1;        
  data[i++] = 0x01;        
  data[i++] = payloadLen;  
  data[i++] = 0x54;       
  data[i++] = 0x02;        
  data[i++] = 0x65;       
  data[i++] = 0x6E;       
  for (uint8_t k = 0; k < textLen; k++) data[i++] = TEXT[k];
  data[i++] = 0xFE;       

  byte blk0[16];
  if (readBlock(0x00, blk0)) {
    blk0[0]  = 0xAA;   
    blk0[12] = 0xE1; blk0[13] = 0x10; blk0[14] = 0x6D; blk0[15] = 0x00;
    writeBlock(0x00, blk0);
    delay(10);
  }

  if (writeBlock(0x01, data)) {
    Serial.println(F("Wrote 'hello' to NFC tag."));
  } else {
    Serial.println(F("Failed to write 'hello'."));
  }
  delay(10); 
}

bool writeBlock(byte blockAddr, byte *buf) {
  Wire.beginTransmission(NFC_ADDR);
  Wire.write(blockAddr);
  for (int i = 0; i < 16; i++) Wire.write(buf[i]);
  return (Wire.endTransmission() == 0);
}

bool readBlock(byte blockAddr, byte *buf) {
  Wire.beginTransmission(NFC_ADDR);
  Wire.write(blockAddr);
  if (Wire.endTransmission(false) != 0) return false; 

  byte n = Wire.requestFrom((int)NFC_ADDR, 16);
  if (n != 16) return false;
  for (int i = 0; i < 16; i++) buf[i] = Wire.read();
  return true;
}
