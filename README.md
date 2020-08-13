# WiFi doorbell
A simple WiFi doorbell using [WiFiManager](https://github.com/tzapu/WiFiManager). After doorbell is rang, notification will show up in mobile app.

## Requirements
- esp8266 microchip (in this example was used Wemos D1 mini module)
- smartphone (most likely with android)

## How to get started
- connect your chip to 3,3V or USB 5V & have your WiFi router on
- check available WiFi connections (from laptop or smartphone) and connect to "Doorbell", password is "esp8266-doorbell-ap"
- connect to your home's WiFi through interface provided after connecting to "Doorbell" WiFi

## Possible problems
- Due to security reasons, Doorbell AP is available for only 15 minutes. If you hadn't managed to connect to Doorbell interface within 15 minutes, simply reboot chip by unplugging & plugging back to voltage.

## Technical background

#### How it works
- After button is pressed, UDP packet with signal is sent onto broadcast with specified port.

#### TODO
- implement sleep CPU mode into main loop in order to reduce energy consumption (https://www.nongnu.org/avr-libc/user-manual/group__avr__sleep.html)
- android app, which receives UDP packet from doorbell on specified port, parses message and notifies user
