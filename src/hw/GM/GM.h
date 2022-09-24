#ifndef GM_H
#define GM_H

#pragma once
#include "mfrc522.h"
#include "Listener.h"
#include "RFID_View.h"
# include "wiringPi.h"
#include "CardReader.h"
#include "Control.h"
#include "GMService.h"


class GM
{
public:
    GM(  );
    ~GM();
    void GM_Run();

TCPServer *server;
CardReader *cardreader;
RFID_View *rfidview1;
GMService  *GMservicer;
Control *cont;
Listener *listener1;




private:

};

#endif