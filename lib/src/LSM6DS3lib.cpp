#include "LSM6DS3lib.hpp"

int LSM6DS3::deviceInit()
{
    //Who I am ID
    if (readRegister(WHO_AM_I) == 0x69) //9.11 dokumentacja
    {
        //konfiguracja urządzenia do pracy po przez wpis do odpowiednich rejestrow
        Serial.println("Device detected!");
        writeRegister(CTRL2_G, 0x4C);
        writeRegister(CTRL1_XL, 0x4A);
        writeRegister(CTRL7_G, 0x00);
        writeRegister(CTRL8_XL, 0x09);
        return 1;
    }
    else
    {
        deviceEnd();
        return 0;
    }
}

void LSM6DS3::deviceEnd()
{
    writeRegister(CTRL2_G, 0x00);
    writeRegister(CTRL1_XL, 0x00);
    writeRegister(CTRL7_G, 0x00);
    writeRegister(CTRL8_XL, 0x00);
    Wire.end();
}

//funkcje prywatne - pomocnicze do odczytu danych
int LSM6DS3::readRegister(uint8_t adress)
{
    int value = 0;
    Wire.beginTransmission(I2C_device_addr); //Rozpoczęcie transmisji I2C
    Wire.write(adress);                      // Wpis do rejestru
    Wire.endTransmission(true);              // Zakończenie transmisji
    value = Wire.read();                     //Odczyt danych
    return value;
}

int LSM6DS3::writeRegister(uint8_t adress, uint8_t data)
{
    int state;
    Wire.beginTransmission(I2C_device_addr);       //Rozpoczęcie transmisji I2C
    Wire.write(adress);                            // Wpis do rejestru
    Wire.write(data);                              // Wpis do rejestru
    state = (Wire.endTransmission() != 0) ? 1 : 0; //zmienna pomocnicza do sprawdzania poprawności skonczenia transmisji
    return state;
}

int LSM6DS3::readTwoRegisters(uint8_t adress, uint8_t *data, size_t length)
{

    Wire.beginTransmission(I2C_device_addr);
    Wire.write(adress);

    if (Wire.endTransmission(false) != 0)
    {
        return -1;
    }
    if (Wire.requestFrom(I2C_device_addr, length) != length)
    {
        return 0;
    }
    for (size_t i = 0; i < length; i++)
    {
        *data++ = Wire.read();
    }
    return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
float LSM6DS3::readAcc(float &x, float &y, float &z)
{

    int16_t data[3]; //tablica przechowująca wartosci dla
    if (!readTwoRegisters(OUTX_L_XL, (uint8_t *)data, sizeof(data)))
    {
        return 0;
    }

    //wyskalowanie wyniku
    x = data[0] * 4.0 / 32768.0;
    y = data[1] * 4.0 / 32768.0;
    z = data[2] * 4.0 / 32768.0;

    return 1;
}

float LSM6DS3::readGyro(float &x, float &y, float &z)
{

    int16_t data[3]; //tablica przechowująca wartosci dla
    if (!readTwoRegisters(OUTX_L_XL, (uint8_t *)data, sizeof(data)))
    {
        return 0;
    }

    //wyskalowanie wyniku
    x = data[0] * 4.0 / 32768.0;
    y = data[1] * 4.0 / 32768.0;
    z = data[2] * 4.0 / 32768.0;

    return 1;
}

float LSM6DS3::readTemperature()
{
    float temp;
    Wire.beginTransmission(I2C_device_addr);
    Wire.write(ACC_GYRO_OUT_TEMP_L);            // Adres od którego odczytujemy dane z żyroskopu
    Wire.endTransmission(false);                // Nie przerywamy transmisji
    Wire.requestFrom(I2C_device_addr, 2, true); // Odczyt danych z 6 rejestrow

    temp = (Wire.read() | Wire.read() << 8); // oś X, OR wynikow z przesunieciem bitowych
    temp = ((float)temp / 16.0f);            // przeskalowanie wyniku
    temp += 25;                              // dodanie offsetu +25

    return temp;
}