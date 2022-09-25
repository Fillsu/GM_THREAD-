#ifndef CONTROL_H
#define CONTROL_H

#pragma once
#include <string>
#include "RFID_View.h"
#include "CardReader.h"
#include "GMService.h"

class Control
{
public:
    Control(RFID_View *rfidview,CardReader *cardread,GMService *GMservicer);
    ~Control();
    void updateRFID(std::string rfidstr);
    void updateDB(std::string rfidstr);
    RFID_View *rfidview;
    CardReader *cardread;
    GMService *GMservicer;
int cardNum[5];

private:

};

#endif