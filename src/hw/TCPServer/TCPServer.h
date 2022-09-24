#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <queue>
#define TCP_PORT 0
class TCPServer
{
public:
    TCPServer(int portNum);
    ~TCPServer();
    void createSocket();
    int waitaccept();
    int readmsg();
    void writemsg(char *mesg_buf);
    void getserversocket();
    void getclientsocket();
    char mesg[BUFSIZ];
    char read_mesg[BUFSIZ];
    char write_mesg[BUFSIZ];
    bool getClientState();
    bool setClientState(int state);
    int clientSock_ft;
private:
    int serverSock_ft;
    
    int portNum;
    int clientState;
    int n;
    
   
    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;
    socklen_t clientadrrsize;

};

#endif