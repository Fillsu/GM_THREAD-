#include "CardReader.h"



CardReader::CardReader(SPI *spi):mfrc522(spi)
{

}

CardReader::~CardReader()
{

}

bool  CardReader:: IsCard()
{

uint8_t byte;

if((byte=mfrc522_request(PICC_REQALL,RFIDData)) == CARD_FOUND )
{

mfrc522_get_card_serial(RFIDData);
return TRUE;
}
return FALSE;

}

Device_Data CardReader:: getCardNumber()
{
mfrc522_get_card_serial(RFIDData);
data.name="cardreadername";
data.number.clear();
for (const auto ndata:RFIDData)
{data.number.push_back((int)ndata);
}
return data;
}