# vday installation creative embedded sys

Code for TTGO T-display ESP32

[Watch Video](https://youtu.be/HUqh9DVShdw?si=L3OKeGKO6dwCmb3V)

Uses [TFT_eSPI library](https://github.com/Bodmer/TFT_eSPI/tree/master) and the [Sprite_TFT_Rainbow.ino](https://github.com/Bodmer/TFT_eSPI/blob/master/examples/Sprite/Sprite_TFT_Rainbow/Sprite_TFT_Rainbow.ino) example from the library where indicated by comment.

All printed text by Lana Del Rey

## How to recreate

### Components
- TTGO T-display ESP32
- USB-C
- Machine that supports [Arduino IDE](https://www.arduino.cc/en/software)

### IDE and libraries
1. [Download Arduino IDE](https://www.arduino.cc/en/software)
2. Launch the IDE and open the Settings/Preferences page: Ardunio --> Settings
3. Copy and paste, https://dl.espressif.com/dl/package_esp32_index.json, into Additional Boards Manager URLs
4. Select Tools -> Manage Library and search for tft_eSPI to install the [TFT_eSPI library by Bodmer](https://github.com/Bodmer/TFT_eSPI/tree/master)
5. In `Ardunio/libraries/TFT_eSPI/User_Setup_Select.h` uncomment the `#include<User_Setups/Setup25_TTGO_T_Display.h>` line

### Download Code and Upload to ESP32
1. Download `vday-installation-creative-embedded-sys.ino` and open in the file in the [Arduino IDE](https://www.arduino.cc/en/software)
2. Connect the TTGO T-display ESP32 and your computer using the USB-C
3. In the [Arduino IDE](https://www.arduino.cc/en/software) select Tools and the corresponding Port
4. Select Upload and enjoy the display

### Artistic Documentation and Installation

Print envelope* files to display the ESP32 as described [here](https://chloeho7.github.io/projects/vday/)

[Watch Video](https://youtu.be/NHFYFbRfrQA)
