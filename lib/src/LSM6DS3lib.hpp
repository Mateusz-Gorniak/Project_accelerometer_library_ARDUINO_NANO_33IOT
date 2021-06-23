#ifndef _LSM6DS3LIB_H_
#define _LSM6DS3LIB_H_
//Importowanie bibliotek
#include "Arduino.h"
#include "Wire.h"

//Deklaracje preprocesora
#define I2C_device_addr 0x6A
#define WHO_AM_I 0x0F
#define LSM6DS3_STATUS_REG 0X1E

//Gyroscope output register
//Registers for gyroscope definition
#define OUTX_L_G 0x22
#define OUTX_H_G 0x23
#define OUTY_L_G 0x24
#define OUTY_H_G 0x25
#define OUTZ_L_G 0x26
#define OUTZ_H_G 0x27

//Accelerometer output register
// Registers for accelerometer definition
#define OUTX_L_XL 0x28
#define OUTX_H_XL 0x29
#define OUTY_L_XL 0x2A
#define OUTY_H_XL 0x2B
#define OUTZ_L_XL 0x2C
#define OUTZ_H_XL 0x2D

class LSM6DS3
{
public:
    int deviceInit();
    int deviceEnd();

    // Accelerometer
    void readAcceleration(float &x, float &y, float &z); // Wynik odczytu akcelerometru
    float accelerationSampleRate();                      // Czestotliwosc probkowania akcelerometru
    int accelerationAvailable();                         // Funkcja sprawdzajaca czy z akcelerometru są odczytywane dane
    //Gyroscoscope
    void readGyroscope(float &x, float &y, float &z); // Wynik odczytu z żyroskopu w stopniach na sekunde
    float gyroscopeSampleRate();                      // Czestotliwosc probkowania żyroskopu
    int gyroscopeAvailable();                         // Funkcja sprawdzajaca czy z żyroskopu są odczytywane dane

    //Temperature
    float readTemperature();

private:
    int readRegister(uint8_t adress);
    int writeRegister(uint8_t adress, uint8_t data);
    int readTwoRegister(uint8_t adress, uint8_t *data, size_t length);
};

#endif