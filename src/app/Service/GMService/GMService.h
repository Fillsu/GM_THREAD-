#ifndef GMSERVICE_H
#define GMSERVICE_H

#pragma once
#include <string>
#include "MemberEntity.h"
#include "MemberInfo.h"
#include "Device_Data.h"
#include "wiringPi.h"
#include "RFID_View.h"

enum {CARD_READ,CARD_REG};

class GMService
{
public:
    GMService();
    ~GMService();
    
    MemberEntity *meberentity;
    MemberInfo temp;
    Device_Data *data;
    RFID_View *rfid_view;

    int GMState;
    char command[30];
    int command_int[5];
    int memeberid;
    int member_add;

    void updateService(std::string GMstr);
    void checkCard(int *cardNum);

private:

};

#endif