#include <LSM6DS3lib.hpp>
#include <Arduino_LSM6DS3.h>

//obiekt klasy LSM6DS3
LSM6DS3 handler;

void setup()
{
  //inicjalizacja portu szeregowego
  Serial.begin(9600);
  Wire.begin();
  while (!Serial)

    if (!IMU.begin())
    {
      Serial.println("Failed to initialize IMU!");
    }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");
  delay(1000);
  handler.deviceInit();
}

void loop()
{
  float x, y, z;
  Serial.println("------------------");
  if (IMU.accelerationAvailable())
  {
    handler.readAcc(x, y, z);
    Serial.println("Acceleration in G's");
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
    delay(300);
  }
  if (IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(x, y, z);
    Serial.println("Gyroscope val in deg/sec");
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
    delay(300);
  }
  //odczyt temperatury
  float temp = handler.readTemperature();
  Serial.print("Temp val in [*C]  = ");
  Serial.print(temp);
  Serial.print('\n');
  Serial.println("------------------");
  delay(300);
}