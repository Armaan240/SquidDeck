# SquidDeck 
this is project is made for highway and it is smart deck which acts an a clock also you can trigger animation in leds when a nfc tap is given ,
it is inspired fromthe world famous seriers,.... yah you guess it right Squid Game as it is been in trending since it launch and and from the 3 season launched recently on netflix 

## What Does It Do
actually things it can done maybe simple but i has power to hold a thing a person can do ,Time ,,.. it shows time using the 24 Circular display And Has Special Nfc Feature by which you can do any thing ,redirect to any video,website ,portifolio, etc....

## Why I made this 
Actually I have made it to bring it on undercity and and show to everyone also i ahve decided to give away free Squid Deck to One person by an lucky draw , anyone can participate in the lucky draw by Taping On the NFC and Pay A fees Of **$10,000** mutiplied by Zero so check your bank balance before partcipating also every 10th tapper will get a free dalgon a candy you also get for $2 but its free only if your able to Crack it properly (all the money collected will be donated to hackclub)

Here are some Picture Of the Project ,Please dont Hate it is a SpeedRun Project MAde Under 8 Hours
![](https://github.com/Armaan240/SquidDeck/blob/main/Images/Screenshot%20(89).png)
![](https://github.com/Armaan240/SquidDeck/blob/main/Images/Screenshot%20(90).png)
![](https://github.com/Armaan240/SquidDeck/blob/main/Images/Screenshot%20(94).png)
![](https://github.com/Armaan240/SquidDeck/blob/main/Images/Screenshot%20(95).png)
![](https://github.com/Armaan240/SquidDeck/blob/main/Images/Screenshot%20(96).png)


## 📦 **Bill of Materials (BOM)**

| Qty | Component                  | Part/Value                | Notes                           | Price(inc Shipping)   | Suggested Source      |
| --- | -------------------------- | ------------------------- | ---------------------------|------------ | --------------------- |
| 1   | Arduino Nano               | ATmega328P (5V/16MHz)     | Main microcontroller          |     $3     | [BUY LINK](https://robu.in/product/arduino-nano-board-r3-with-ch340-chip-wo-usb-cable-solderedarduino-nano-r3-wo-usb-cable-soldered/?gad_source=1&gad_campaignid=21296336107&gbraid=0AAAAADvLFWe5m4OOkmR2LNtzIEoBUXSvU&gclid=CjwKCAjwsZPDBhBWEiwADuO6yw6JJ3JU634LgVe0-yi93Z_FVmzT61gwPTG-l0kZ5r9OSR2vN1FQ5xoChNYQAvD_BwE) |
| 1   | NFC Chip                   | NT3H2111W0FT1X            | I²C + Field Detect NFC IC    | $1          |    [BUY LINK](https://www.arrow.com/en/products/nt3h2111w0fhkh/nxp-semiconductors?utm_source=google&utm_medium=cpc&utm_campaign=brand_g-pmax_product-feed_in_q1_2025&utm_content=apac_en&gad_source=1&gad_campaignid=20534936583&gbraid=0AAAAADFaomPckbFfZd3NQ-tgIt4w26QHF&gclid=CjwKCAjwsZPDBhBWEiwADuO6y0Z-YGp9IETI6SeR1XwWFN3RqCi52DX2vvzgK5XX7-oIvww11lwE7hoCDiUQAvD_BwE&gclsrc=aw.ds)         |
| 1   | LED Strip                  | 24× WS2812B LEDs          | Individually addressable RGB   |     $5    |   [BUY LINK](https://www.electronicscomp.com/24-bit-ws2812-5050-rgb-led-built-in-full-color-driving-lights-circular-development-board?srsltid=AfmBOopHv9CPycDlo-qvJMQ06DFPkfF7PhE7R8qQ-_-dKPN-fcNRGsAnHpI)   |
| 1   | Charging Module            | TP4056 + Protection       | LiPo charging + 5V out        |      $1.5    |  [BUY LINK](https://www.amazon.in/Robotbanao-TP4056-Lithium-Battery-Charging/dp/B09PDS65FB)        |
| 1   | 3.3V Regulator             | AMS1117-3.3 or equivalent | Powers NFC chip and pull-ups  |    $0.3      |    [BUY LINK]([AMS1117-3.3](https://robu.in/product/ams1117-3-3-slkor-70db120hz-1a-fixed-3-3v-positive-electrode-18v-sot-89-3-voltage-regulators-linear-low-drop-out-ldo-regulators-rohs/))      |
| 2   | Pull-up Resistors          | 4.7kΩ, 1/8W               | For SDA and SCL lines         |    $0.2      |     sourced locally              |
| 1   | Series Resistor for DIN    | 330Ω                      | Between Nano D6 and LED DIN   |     -     |   have it          |
| 1   | Filter Capacitor           | 1000 µF, 6.3V or higher   | Across LED VCC & GND          |    -     |      have it       |
| 1   | LiPo Battery               | 3.7V 500–1000mAh          | Power source                   |   $3      |     Sourced Locally     |
| 1   | NFC Antenna                | Wire loop / PCB trace     | \~1–2 µH; hand-wound or spiral on board|  $1    |  handmade       |
| 1   | Slide Switch (Power)       | SPDT                      | Main power control              |     -   |     have it          |
| 1   | JST Connector              | 2-pin (LiPo)              | For battery plug-in              |   -    |    have it         |
| 1   | Micro USB Port             | For charging              | On TP4056 board                 |    -    |     have it          |
| -   | PCB (custom round, \~60mm) | Circular 2-layer          | Your custom design               |    $10   | Seed Studio       |



## Grand Total ~ $ 25-27
