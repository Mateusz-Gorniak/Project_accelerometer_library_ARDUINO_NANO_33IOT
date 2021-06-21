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

class LSM6DS3
{
public:
    int LSM6DS3_init();
    int LSM6DS3_write();
    int LSM6DS3_read();

private:
    int readRegister(uint8_t adress);
    int writeRegister(uint8_t adress);
    int readRegisterMultiple(uint8_t adress);
};

#endif