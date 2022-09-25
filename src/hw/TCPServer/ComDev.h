#ifndef COMDEV_H
#define COMDEV_H

#pragma once
#include "TCPServer.h"
class ComDev
{
public:
    ComDev();
    ~ComDev();
    void sendData(char *writemesg);
    void CompleteSend();
    TCPServer *server;
private:

};

#endif