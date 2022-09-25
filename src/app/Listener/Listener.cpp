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
search_name[9]='\0';

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
             int j=5;
             int k=0;
             
             int d=7;
             int e=0;

             static int precard=0;
             static int timer=0;
            if(!(msgqueue->empty()))
            {
           // std::cout<<" "<<std::endl ;
            while(!(msgqueue->front()=='\0'))
            {
            
           //std::cout<<msgqueue->front()<<std::endl ;
            comp[i]=msgqueue->front();
            //printf("%c",msgqueue->front());
            msgqueue->pop();
            i++;
            }
            comp[i]='\0';
            msgqueue->pop();

                if(strncmp(comp,"Find",4)==0)
                {
                    //std::cout<<"check"<<std::endl;
                
                while(!(comp[j]=='\0'))
                {
                //comp[j]=search_name[k];어휴 ㅉㅉ
                search_name[k]=comp[j];
                j++;
                k++;
                }         
                    search_name[k]='\0';
                    //std::cout<<search_name<<std::endl;         
                    comp[0]='\0';
                    cont->updateRFID(search_name);
                    return ;
                }

                if(strncmp(comp,"Delete",6)==0)
                {
                    //std::cout<<"check"<<std::endl;
                
                while(!(comp[d]=='\0'))
                {
                //comp[j]=search_name[k];어휴 ㅉㅉ
                delete_name[e]=comp[d];
                d++;
                e++;
                }         
                    delete_name[e]='\0';
                    //std::cout<<search_name<<std::endl;         
                    comp[0]='\0';
                    cont->updateDB(delete_name);
                    return ;
                }



                 if(strcmp(comp,"start")==0)
                {
                    //std::cout<<"check"<<std::endl;
                    comp[0]='\0';
                    cont->updateRFID("start");
                    return ;
                }

                 if(strcmp(comp,"Card search")==0)
                {
                    //std::cout<<"check"<<std::endl;
                    comp[0]='\0';
                    cont->updateRFID("search");
                    timer=millis();
                    while(1)
                    {
                        if(millis()-precard>1000)
                        {
                            if(cardread->IsCard()==1 )
                            {       
                                precard=millis();
                                cardread->getCardNumber();
                                cont->updateRFID("SERVERneedsCardRead");
                                break;
                                
                            }
                        }   

                        if(millis()-timer>10000)
                        {
                            break;       
                        }

                    
                    }
                    return ;
                }
                //std::cout<<"wrong"<<std::endl;
                comp[0]='\0';
                cont->updateRFID("wrong");
                

            }


       


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