#ifndef _LSM6DS3LIB_H_
#define _LSM6DS3LIB_H_
//Importowanie bibliotek
#include "Arduino.h"
#include "Wire.h"

//Deklaracje preprocesora
#define I2C_device_addr 0x6A
#define WHO_AM_I 0x0F
#define LSM6DS3_STATUS_REG 0X1E
#define CTRL1_XL 0X10
#define CTRL2_G 0X11
#define STATUS_REG 0X1E
#define CTRL6_C 0X15
#define CTRL7_G 0X16
#define CTRL8_XL 0X17

// Rejestry - zyroskop
#define OUTX_L_G 0x22
#define OUTX_H_G 0x23
#define OUTY_L_G 0x24
#define OUTY_H_G 0x25
#define OUTZ_L_G 0x26
#define OUTZ_H_G 0x27

// Rejestry - akcelerometr
#define OUTX_L_XL 0x28
#define OUTX_H_XL 0x29
#define OUTY_L_XL 0x2A
#define OUTY_H_XL 0x2B
#define OUTZ_L_XL 0x2C
#define OUTZ_H_XL 0x2D

// Rejestry - temperatura
#define ACC_GYRO_OUT_TEMP_L 0X20

class LSM6DS3
{
public:
    int deviceInit();
    void deviceEnd();

    // Accelerometer
    float readAcc(float &x, float &y, float &z); // Wynik odczytu akcelerometru
    float accelerationSampleRate();              // Czestotliwosc probkowania akcelerometru
    int accelerationAvailable();                 // Funkcja sprawdzajaca czy z akcelerometru są odczytywane dane
    //Gyroscoscope
    float readGyroscope(float &x, float &y, float &z); // Wynik odczytu z żyroskopu w stopniach na sekunde
    float gyroscopeSampleRate();                       // Czestotliwosc probkowania żyroskopu
    int gyroscopeAvailable();                          // Funkcja sprawdzajaca czy z żyroskopu są odczytywane dane

    //Temperature
    float readTemperature();

private:
    int readRegister(uint8_t adress);
    int writeRegister(uint8_t adress, uint8_t data);
    int readTwoRegisters(uint8_t adress, uint8_t *data, size_t length);
};

#endif