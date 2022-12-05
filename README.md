Update `\.pio\libdeps\adafruit_feather_esp32s2_tft\TFT_eSPI\User_Setup.h` to match your specifications.

# PG4501 Exam - Gaming Console

Embedded Systems gaming console software.

I tried to use as little memory as possible. This way I have more memory on the arduino uno for functionality. An example of this is by using pointers when passing a variable into a function. Change the original value, instead of making a copy.

## Code files

### <b>pg4501-exam.ino</b>

Is the main program. Runs everything related to the application.

### <b>memory.cpp</b>

All SD card logic. Everything related to saving or retrieving files from the SD card.

Header files

- memory.h

### <b>display.cpp</b>

All TFT screen logic. Everything related to displaying sprites and text on the ST7789 TFT screen.

Header files

- display.h

### <b>joystick.cpp</b>

The joystick logic. Input data that is saved as public variables. Other programs uses these values to map out the player movement.

Header files

- joystick.h

### <b>donkeyKongGame.cpp</b>

One of the games. Donkey Kong Arcade edition. A simplistic version of the classic arcade game. <b>joystick.h</b> is used to move the player.
<b>display.h</b> is used to show the different sprites that the <b>memory.h</b> gets from the SD-card. All the required sprites (bmp) are retrieved and
saved in memory, then drawn on to the screen.

Header files

- donkeyKongGame.h

## References

### Libraries

- TFT_eSPI by Bodmer
- TJpg_Decoder by Bodmer
- JPEGDecoder by Bodmer
- PNGdec by Larry Bank

[Joystick logic](https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0)<br>
[Transparent Sprites - Programming Tutorial (TFT_eSPI library)](https://www.youtube.com/watch?v=U4jOFLFNZBI&t=1002s&ab_channel=VolosProjects)

### Inspiration

[Arduino - How to Split a Program Into Different Files](https://www.youtube.com/watch?v=BdstuZP6l5E&ab_channel=RoboticsBack-End)<br>
[Arcade Donkey Kong](https://www.youtube.com/watch?v=UBHJhla8TO4&t=89s&ab_channel=WorldofLongplays)<br>
[Mario sprites](https://www.mariowiki.com/Gallery:Mario_sprites_and_models)
