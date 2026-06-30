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

<img width="400" height="711" alt="mew" src="https://github.com/user-attachments/assets/74cb9a47-4381-43d8-8cf9-159a7324c401" />
<img width="392" height="391" alt="mewww" src="https://github.com/user-attachments/assets/4d40abcd-377e-44e5-92c6-9454713155cf" />

<img width="4284" height="5712" alt="IMG_4992" src="https://github.com/user-attachments/assets/988dafd9-4b0a-4c54-bc52-ddb6c5f9ce36" />

<img width="1197" height="513" alt="Screenshot (214)" src="https://github.com/user-attachments/assets/a03e8f08-05d9-4a25-bf6a-d663937c63eb" />
<img width="828" height="596" alt="Screenshot (215)" src="https://github.com/user-attachments/assets/4090429e-ed4b-409f-9b5c-22a53587eee5" />
<img width="571" height="531" alt="Screenshot (216)" src="https://github.com/user-attachments/assets/277310e3-59f4-4857-8204-2f0f4f48b616" />



## 📦 **Bill of Materials (BOM)**

| Qty | Component                  | Part/Value                | Notes                           | Price(inc Shipping)   | Suggested Source      |
| --- | -------------------------- | ------------------------- | ---------------------------|------------ | --------------------- |
| 1   | Arduino Nano               | ATmega328P (5V/16MHz)     | Main microcontroller          |     $3     | [BUY LINK](https://robu.in/product/arduino-nano-board-r3-with-ch340-chip-wo-usb-cable-solderedarduino-nano-r3-wo-usb-cable-soldered/?gad_source=1&gad_campaignid=21296336107&gbraid=0AAAAADvLFWe5m4OOkmR2LNtzIEoBUXSvU&gclid=CjwKCAjwsZPDBhBWEiwADuO6yw6JJ3JU634LgVe0-yi93Z_FVmzT61gwPTG-l0kZ5r9OSR2vN1FQ5xoChNYQAvD_BwE) |
| 1   | NFC Chip                   | NT3H2111W0FT1X (SO8)      | I²C + Field Detect NFC IC, 50pF input cap | $1 | [BUY LINK](https://www.arrow.com/en/products/nt3h2111w0fhkh/nxp-semiconductors?utm_source=google&utm_medium=cpc&utm_campaign=brand_g-pmax_product-feed_in_q1_2025&utm_content=apac_en&gad_source=1&gad_campaignid=20534936583&gbraid=0AAAAADFaomPckbFfZd3NQ-tgIt4w26QHF&gclid=CjwKCAjwsZPDBhBWEiwADuO6y0Z-YGp9IETI6SeR1XwWFN3RqCi52DX2vvzgK5XX7-oIvww11lwE7hoCDiUQAvD_BwE&gclsrc=aw.ds) |
| 1   | LED Ring                   | 24× WS2812B (86mm)        | Individually addressable RGB   |     $5    |   [BUY LINK](https://www.electronicscomp.com/24-bit-ws2812-5050-rgb-led-built-in-full-color-driving-lights-circular-development-board?srsltid=AfmBOopHv9CPycDlo-qvJMQ06DFPkfF7PhE7R8qQ-_-dKPN-fcNRGsAnHpI)   |
| 1   | Charging Module            | TP4056 + Protection       | LiPo charging + 5V out        |      $1.5    |  [BUY LINK](https://www.amazon.in/Robotbanao-TP4056-Lithium-Battery-Charging/dp/B09PDS65FB)        |
| 1   | 3.3V Regulator             | AMS1117-3.3               | Powers NFC chip + level-shifter LV side  |    $0.3      |    [BUY LINK](https://robu.in/product/ams1117-3-3-slkor-70db120hz-1a-fixed-3-3v-positive-electrode-18v-sot-89-3-voltage-regulators-linear-low-drop-out-ldo-regulators-rohs/)      |
| 3   | Level Shifter MOSFETs      | BSS138BK (SOT-23)         | 5V↔3.3V on SDA, SCL, FD       |    $0.15  |     have it          |
| 6   | Pull-up Resistors          | 4.7kΩ, 1/4W               | Two per level-shifter channel (double as I²C pull-ups) |    $0.2      |     sourced locally              |
| 1   | Series Resistor for DIN    | 330Ω                      | Between Nano **D4** and LED DIN |     -     |   have it          |
| 1   | Regulator Input Cap        | 10µF electrolytic         | AMS1117 input                  |    -     |      have it       |
| 1   | Regulator Output Cap       | 22µF electrolytic         | AMS1117 output (stability)     |    -     |      have it       |
| 1   | LED Filter Capacitor       | 220 µF, 6.3V or higher    | Across LED VCC & GND          |    -     |      have it       |
| 1   | NFC VOUT Cap               | 150–220nF ceramic         | VOUT → GND (energy-harvest stability) |    -     |      have it       |
| 1   | Battery                    | 5V 500–1000mAh           | Power source                   |   $3      |     Sourced Locally     |
| 1   | NFC Antenna                | ~2.7µH coil, 13.56MHz     | Tuned to chip's 50pF; hand-wound / spiral |  $1    |  handmade       |
| 1   | Slide Switch (Power)       | SPDT                      | Main power control              |     -   |     have it          |
| 1   | JST Connector              | 2-pin (LiPo)              | For battery plug-in              |   -    |    have it         |
| 1   | Micro USB Port             | For charging              | On TP4056 board                 |    -    |     have it          |
| -   | PCB (custom round, ~60mm)  | Circular 2-layer          | Your custom design               |    $10   | JLC       |

## Grand Total ~ $25-27

