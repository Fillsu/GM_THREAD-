#ifndef GMSERVICE_H
#define GMSERVICE_H

#pragma once
#include <string>
#include "MemberEntity.h"
#include "MemberInfo.h"
#include "Device_Data.h"
#include "wiringPi.h"
#include "RFID_View.h"
#include "ComDev.h"
#include "TCPServer.h"
#include <thread>
#include <unistd.h>
#include <queue>

enum {CARD_READ,CARD_REG,CARD_START};

class GMService
{
public:
    GMService(ComDev *component);
    ~GMService();
    
    MemberEntity *meberentity;
    MemberInfo temp;
    Device_Data *data;
    RFID_View *rfid_view;
    ComDev *component;
    //TCPServer *server;
    int GMState;
    char command[30];
    int command_int[5];
    char write_buf[200];
    char write_mesg[200];
    void updateService(std::string GMstr);
    void checkCard(int *cardNum);
    void checkName_server(std::string Findstr);
    void checkCard_server(int *cardNum);
    void Delete_member(std::string Findstr);
private:
    int memeberid;
    int member_add;
};

#endif