#include "LSM6DS3lib.hpp"

int LSM6DS3::deviceInit()
{
    return 0;
}

float LSM6DS3::readTemperature()
{
    float temp;
    Wire.beginTransmission(I2C_device_addr);
    Wire.write(0x20);                           // Adres od którego odczytujemy dane z żyroskopu
    Wire.endTransmission(false);                // Nie przerywamy transmisji
    Wire.requestFrom(I2C_device_addr, 2, true); // Odczyt danych z 6 rejestrow

    temp = (Wire.read() | Wire.read() << 8); // oś X, OR wynikow z przesunieciem bitowych
    temp = ((float)temp / 16.0f);            // przeskalowanie wyniku
    temp += 25;                              // dodanie offsetu +25

    return temp;
}