## Project_accelerometer_library_ARDUINO_NANO_33IOT

This project contains my own dedicated library for the accelerometer LSM6DS3 from the Arduino Nano 33 IOT board.

### Datasheet

The library is intended only for the Arduino NANO 33 IoT development kit. It is adapted to connections connecting the I2C communication interface. </br>
The library does not support the SPI interface.</br></br>

The library was created on the PlatformIO platform. Before starting work, install the Atmel SAM framework and modify the project's properties accordingly.

[env:nano_33_iot]
platform = atmelsam
board = nano_33_iot
framework = arduino
