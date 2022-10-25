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

static int precard=0;
int i=0;//this is for msgqueue

int Find_comp=5;//this is for 'Find Commnad'
int Find_factor=0;

int Delete_comp=7;//this is for 'Delete Commnad'
int Delete_factor=0;

static int timer=0;

if(!(msgqueue->empty()))
{
//메세지큐에 저장되있는 문자열을 Pop
	while(!(msgqueue->front()=='\0'))
	{	
		comp[i]=msgqueue->front();
		msgqueue->pop();
		i++;
	}
	
	comp[i]='\0';
	msgqueue->pop();

//Find 문자열 필터링 	
	if(strncmp(comp,"Find",4)==0)
	{
		while(!(comp[Find_comp]=='\0'))
		{
			search_name[Find_factor]=comp[Find_comp];
			Find_factor++;
			Find_comp++;
		}         
		search_name[Find_factor]='\0';    
		comp[0]='\0';
		cont->updateRFID(search_name);
		return ;
	}
//Delete 문자열 필터링 	
	if(strncmp(comp,"Delete",6)==0)
	{
		while(!(comp[Delete_comp]=='\0'))
		{
			delete_name[Delete_factor]=comp[Delete_comp];
			Delete_comp++;
			Delete_factor++;
		}         
		delete_name[Delete_factor]='\0';       
		comp[0]='\0';
		cont->updateDB(delete_name);
		return ;
	}
//Start 문자열 필터링 
	if(strcmp(comp,"start")==0)
	{
		comp[0]='\0';
		cont->updateRFID("start");
		return ;
	}
//Card Search 문자열 필터링 	
	if(strcmp(comp,"Card search")==0)
	{
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
				cont->updateRFID("ServerNeedsCardRead");
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
//Command 비교가 다 끝았으면 comp를 공백으로 만들어준다. 
//만약 잘못된 명령어가 입력되었을때는 wrong을 메세지를 전달한다. 
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