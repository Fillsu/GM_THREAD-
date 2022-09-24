#include "Listener.h"

Listener::Listener(CardReader *cardread,Control*cont)//:rfid(rfid)
{
//this->rfid=rfid;
this->cont=cont;
this->cardread=cardread;
modeButton=new ManageButton(27,"modebutton");
//this->rfid_viewer=rfid_viewer;
//this->rfid_viewer->data=&(this->cardread->data);
//a=RFIDData;
}

Listener::~Listener()
{

}


// void Listener::checkEvent()
// {
//     uint8_t byte;
// std::cout<<"fdsaf"<<std::endl;
// if((byte=rfid->mfrc522_request(PICC_REQALL,RFIDData)) == CARD_FOUND )
// {

// rfid->mfrc522_get_card_serial(RFIDData);
// for(int i=0;i<5;i++)
// {

//     printf("%02x ",RFIDData[i]);

// }
// }
    
// }



void Listener::checkEvent()
{
             int i=0;
            if(!(msgqueue->empty()))
            {
           // std::cout<<" "<<std::endl ;
            while(!(msgqueue->front()=='\0'))
            {
            
            std::cout<<msgqueue->front()<<std::endl ;
            comp[i]=msgqueue->front();
            //printf("%c",msgqueue->front());
            msgqueue->pop();
            i++;
            }
            comp[i]='\0';
            msgqueue->pop();


                 if(strcmp(comp,"search")==0)
                {
                    std::cout<<"check"<<std::endl;
                    comp[0]='\0';
                    cont->updateRFID("search");
                }
                else
                {
                std::cout<<"wrong"<<std::endl;
                comp[0]='\0';
                cont->updateRFID("wrong");
                }

            }


       

static int precard=0;
if(millis()-precard>1000)
{
    if(cardread->IsCard()==1 )
    {       
        precard=millis();
        cardread->getCardNumber();
        cont->updateRFID("CARDREAD");
        
        // rfid_viewer->updateView("CARDCHECK");
    }
}
if(modeButton->checkButton())
{

     cont->updateRFID("MODECHECK");
   // std::cout<<"dd"<<std::endl;
   //printf("ddfasdfsdf");
 

}

}

bool  Listener::checkRFID()
{
    uint8_t byte;

if((byte=rfid->mfrc522_request(PICC_REQALL,RFIDData)) == CARD_FOUND )
{

rfid->mfrc522_get_card_serial(RFIDData);
return TRUE;
}
return FALSE;


}