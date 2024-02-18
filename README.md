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
- Battery
- Power Cable included with the TTGO T-display

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

### Installation

1. Print envelope* files and fold to display the ESP32 as shown [here](https://chloeho7.github.io/projects/vday/)
2. Put a hole in a popsicle stick and thread a string through the hole
3. Punch a hole in the envelope
4. Wrap the exposed metal parts of the power cord with shrink wrap such that they do not touch when connected to the battery
5. Conncect battery wires and Power cable wires
![pluggingin](https://github.com/chloeho7/vday-installation-creative-embedded-sys/assets/56209417/6cb58860-c3bd-4030-ba6c-ed9e41de1f15)
7. Plug into TTGO T-display
8. Place the TTGO T-display in the envelope such that it is relatively centered as show
![inside](https://github.com/chloeho7/vday-installation-creative-embedded-sys/assets/56209417/53e16b8c-3032-4961-9a4c-b4a6ba73aa94)
![outside](https://github.com/chloeho7/vday-installation-creative-embedded-sys/assets/56209417/0fcd6381-22e7-4a7d-89ff-afe82255e675)
9. Tape the display in place inside the envelope and tuck the battery inside
![insidetaped](https://github.com/chloeho7/vday-installation-creative-embedded-sys/assets/56209417/d9e79b8f-bfcb-46c0-bad6-b97172d48368)
10. Tape the envelope closed and attach the string through the punched hole
![outsidetaped](https://github.com/chloeho7/vday-installation-creative-embedded-sys/assets/56209417/69c226ee-3b54-4390-bdc8-1fa66d970573)
![string](https://github.com/chloeho7/vday-installation-creative-embedded-sys/assets/56209417/f31a7576-ec8a-4850-91eb-a885ba8b453a)


[Watch Video](https://youtu.be/NHFYFbRfrQA)
