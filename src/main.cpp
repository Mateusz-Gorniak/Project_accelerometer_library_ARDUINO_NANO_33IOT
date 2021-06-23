#include <LSM6DS3lib.hpp>
#include <Arduino_LSM6DS3.h>

LSM6DS3 handler;

void setup()
{
  Serial.begin(9600);
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

  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x, y, z);
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
    Serial.println("Gyroscope val");
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
    delay(300);
  }
  float temp = handler.readTemperature();
  Serial.println("Temp val");
  Serial.print(temp);
  Serial.print('\t');
  delay(300);

}