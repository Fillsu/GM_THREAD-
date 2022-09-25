#include "ComDev.h"

ComDev::ComDev()
{
server=new TCPServer(5100);
}

ComDev::~ComDev()
{

}

void ComDev::sendData(char *writemesg)
{
  
server->WriteMsg(writemesg);//아니 미쳤나??

}

void ComDev::CompleteSend()
{

server->closesocket();

}