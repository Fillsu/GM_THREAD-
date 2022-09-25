#ifndef LISTENER_H
#define LISTENER_H

#pragma once
#include <iostream>
#include "mfrc522.h"
#include "RFID_View.h"
#include "CardReader.h"
#include "Control.h"
#include "Device_Data.h"
#include "ManageButton.h"
#include <queue>
class Listener
{
public:
    Listener(CardReader *cardread,Control*cont);


    ~Listener();
    Control *cont;
    
     void checkEvent();
     mfrc522 *rfid;
    uint8_t RFIDData[16];
    bool checkRFID();
    CardReader *cardread;
    RFID_View *rfid_viewer;
    void updateView();
    uint8_t *a;
    ManageButton *modeButton;
    std::queue<char> *msgqueue;
   
    char delete_name[20];
    char search_name[20];
    char comp[10];
private:

};

#endif