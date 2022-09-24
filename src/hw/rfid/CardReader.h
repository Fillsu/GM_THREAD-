#ifndef CARDREADER_H
#define CARDREADER_H

#pragma once
#include "mfrc522.h"
#include "Device_Data.h"
class CardReader:public mfrc522
{
public:
    CardReader(SPI *spi);
    ~CardReader();
    bool IsCard();
    Device_Data getCardNumber();
uint8_t RFIDData[16];   
Device_Data data;
private:

};

#endif