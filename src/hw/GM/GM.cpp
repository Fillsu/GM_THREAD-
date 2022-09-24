#include "GM.h"



//new는 포인터를 반환한다 하지만 그냥 할 때는 그냥 선언해서 썼었다 이게 다르다 
//이러면 귀찮게 일일이 안만들어서 안 넣어줘도 된다. 
GM::GM(  ):cardreader(new CardReader(new SPI(10,3000000))),rfidview1(new RFID_View),GMservicer(new GMService),cont(new Control(rfidview1,cardreader,GMservicer)),listener1(new Listener(cardreader,cont))
{

}

GM::~GM()
{

}

void GM::GM_Run()
{
while(1)

{
listener1->checkEvent();

delay(10);

}
}