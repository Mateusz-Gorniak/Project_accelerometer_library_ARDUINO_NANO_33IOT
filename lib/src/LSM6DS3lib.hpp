#ifndef _LSM6DS3LIB_H_

//Importowanie bibliotek
#include "Arduino.h"
#include "Wire.h"

//Deklaracje preprocesora
#define I2C_device_addr 0x6A
#define WHO_AM_I 0x0F

//Gyroscope output register
// zdefiniowanie rejestrów wyjścia żyroskopu
#define OUTX_L_G 0x22
#define OUTX_H_G 0x23
#define OUTY_L_G 0x24
#define OUTY_H_G 0x25
#define OUTZ_L_G 0x26
#define OUTZ_H_G 0x27

//Accelerometer output register
// zdefiniowanie rejestrów wyjścia akcelerometru
#define OUTX_L_XL 0x28
#define OUTX_H_XL 0x29
#define OUTY_L_XL 0x2A
#define OUTY_H_XL 0x2B
#define OUTZ_L_XL 0x2C
#define OUTZ_H_XL 0x2D

// Return values
typedef enum
{
    SUCCESS,
    HW_ERROR,
    NOT_SUPPORTED,
    GENERIC_ERROR,
    OUT_OF_BOUNDS,
    ALL_ONES_WARNING,

} status_t;

class LSM6DS3
{
public:
    int deviceInit();
    int deviceEnd();

    // Accelerometer
    int readAcceleration(float &x, float &y, float &z); // Results are in g (earth gravity).
    float accelerationSampleRate();                     // Sampling rate of the sensor.
    int accelerationAvailable();                        // Check for available data from acceler
                                                        //Gyroscoscope
    int readGyroscope(float &x, float &y, float &z);    // Results are in degrees/second.
    float gyroscopeSampleRate();                        // Sampling rate of the sensor.
    int gyroscopeAvailable();                           // Check for available data from gyroscope

private:
    int readRegister(uint8_t adress);
    int writeRegister(uint8_t adress, uint8_t data);
    int readRegisterMultiple(uint8_t adress, uint8_t *data, size_t length);
};

#endif