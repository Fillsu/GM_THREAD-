#include "TCPServer.h"

TCPServer::TCPServer(int portNum)
{
this->portNum=portNum;
createSocket();

}

TCPServer::~TCPServer()
{
    close(serverSock_ft);
}

void TCPServer::createSocket()
{
    /* 서버 소켓 생성 */
    if((serverSock_ft = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket()");
       return ;
    }
    int option=1;
    setsockopt(serverSock_ft,SOL_SOCKET,SO_REUSEADDR,&option,sizeof(option));
    /* 주소 구조체에 주소 지정 */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portNum); 	/* 사용할 포트 지정 */
    /* bind 함수를 사용하여 서버 소켓의 주소 설정 */
    if(bind(serverSock_ft, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("bind()");
        return ;
    }
    /* 동시에 접속하는 클라이언트의 처리를 위한 대기 큐를 설정 */
    if(listen(serverSock_ft, 8) < 0) 
    {
        perror("listen()");
        return ;
    }
   printf("server is complete\n");
}

int  TCPServer::waitaccept()
{    
    
    clientadrrsize = sizeof(client_addr);
    /* 클라이언트가 접속하면 접속을 허용하고 클라이언트 소켓 생성 */
    clientSock_ft = accept(serverSock_ft, (struct sockaddr *)&client_addr, &clientadrrsize);
    inet_ntop(AF_INET, &client_addr.sin_addr, mesg, BUFSIZ);
    printf("Client is connected : %s\n", mesg);
    if(clientSock_ft<0)
    {
        printf("accept() fail");
        
    }
    /* 네트워크 주소를 문자열로 변경 */

    return clientSock_ft;
}

    int TCPServer:: readmsg()
  {    
    
        int len=0;
        if((len = read(clientSock_ft, read_mesg, BUFSIZ)) <= 0)
       { 
        perror("read()");
        return 0;
        }                    
        
        //printf("Received data : %s\n", read_mesg);
           

//        printf("Received data lenth : %d\n", strlen(read_mesg));
        if(strncmp(read_mesg,"q",1)==0)
        return 0;

        return len;

  }

    void TCPServer:: writemsg(char *mesg_buf)
  {     //int n=3; 
  
        //strcpy(write_mesg,"ok");
        if(write(clientSock_ft,mesg_buf, 20) <= 0)
        perror("write()");
        close(clientSock_ft); 
  }


  bool TCPServer:: getClientState()
  {

        return clientState;

  }

  
  bool TCPServer:: setClientState(int state)
  {

clientState=state;
    return 0;
  }