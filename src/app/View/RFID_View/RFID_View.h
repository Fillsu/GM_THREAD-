#ifndef RFID_VIEW_H
#define RFID_VIEW_H

#pragma once
#include <iostream>
#include <stdio.h>
#include "wiringPi.h"
#include <string>
#include "Device_Data.h"
#include "LCD.h"
class RFID_View
{
public:
    RFID_View();
    ~RFID_View();
    void updateView(std::string rfidstr);
    uint8_t *RFIDData;
    Device_Data *data;
    LCD *lcd;

    char lcdbuf[20];

private:

};

#endif