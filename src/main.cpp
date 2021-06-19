#include <LSM6DS3lib.hpp>
#include <Arduino_LSM6DS3.h>

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
}

void loop()
{
  float x, y, z;

  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
    delay(1000);
  }
}