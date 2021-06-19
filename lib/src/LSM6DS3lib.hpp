#ifndef _LSM6DS3LIB_H_

//Importowanie bibliotek
#include "Arduino.h"
#include "Wire.h"

class LSM6DS3
{
public:
    void LSM6DS3_init();
    void LSM6DS3_write();
    void LSM6DS3_read();

private:
};

#endif