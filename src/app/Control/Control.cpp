#include "Control.h"
#include "Service.h"
#include "Device_Data.h"

Control::Control(RFID_View *rfidview,CardReader *cardread,GMService *GMservicer)
{
this->GMservicer=GMservicer;
this->rfidview=rfidview;
this->cardread=cardread;
this->rfidview->data=&(this->cardread->data);
this->GMservicer->data=&(this->cardread->data);
}

Control::~Control()
{

}

 void Control::updateRFID(std::string rfidstr)
 {

if(rfidstr=="CARDREAD")
{
//cardread->getCardNumber();
//rfidview->updateView("CARDCHECK");
//GMservicer->updateService(std::string GMstr)
//강제로 배열로 바꾸어서 했으므로 똑같이 해주는 것은 일리가 있다. 
cardNum[0]=cardread->data.number[0];
cardNum[1]=cardread->data.number[1];
cardNum[2]=cardread->data.number[2];
cardNum[3]=cardread->data.number[3];
cardNum[4]=cardread->data.number[4];
GMservicer->checkCard(cardNum);//아하 이거 없으니까 unused 뜸 

}

if(rfidstr=="MODECHECK")
{
   // std::cout<<"dd"<<std::endl;
GMservicer->updateService("MODECHECK");


}

}