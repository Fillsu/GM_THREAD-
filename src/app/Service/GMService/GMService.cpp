#include "GMService.h"


GMService::GMService(ComDev *component):meberentity(new MemberEntity)
{
// this->server=server;
 GMState=CARD_READ;
 memeberid=meberentity->InfoList.size();
 member_add=0;
 rfid_view=new RFID_View();
 this->component=component;


}

GMService::~GMService()
{

}


 void GMService::updateService(std::string GMstr)
{   // std::cout<<" "<<std::endl;
   
   if(GMstr=="start")
    {   
        component->sendData("Golf Management Starts\nPlease type Command:\n\n");
        component->CompleteSend();
        return ;
    }
   if(GMstr=="search")
    {   

        component->sendData("You got search\nuse member card:\n\n");
        component->CompleteSend();
        return ;
    }

       if(GMstr=="wrong")
    {   
        //sprintf(write_buf,"you got wrong");
       // server->writemsg(write_buf);
        component->sendData("you got wrong\n\n");
        component->CompleteSend();
        return ;
    }
    switch (GMState)
    {


    case CARD_READ:
    if(GMstr=="MODECHECK")
    {   //int a=0;
        GMState=CARD_REG;
       sprintf(rfid_view->lcdbuf,"REGISTERING      ");
       sprintf(rfid_view->lcdbuf2,"Use your card");
        
        rfid_view->updateView("CARDCHECK");
        //std::cout<<"REGISTERING"<<std::endl;
     //  printf("REGISTERING");

        
        //std::cout<<command<<std::endl;
    }
    break;
    case CARD_REG:
    if(GMstr=="MODECHECK")
    {
        GMState=CARD_READ;
       // std::cout<<"READING"<<std::endl;
        sprintf(rfid_view->lcdbuf,"Welcome GolfFild");
        sprintf(rfid_view->lcdbuf2,"Use your card");
       rfid_view->updateView("CARDCHECK");
      // std::cout<<"READING"<<std::endl;
       // printf("READING");
    }
    break;
    }
 }


  void GMService::checkCard(int *cardNum)
 {
            //      for(int i=0;i<5;i++)
            // { 
            //    // printf("ddd %d",a);
            //     printf(" %x ",*(cardNum+i));

            // }
    switch (GMState)
    {
    case CARD_READ:
    if((meberentity->FindInfo(cardNum))==1)
    {    
        //meberentity->printfInfo(cardNum);
       // printf("Registered Number\n");
        sprintf(rfid_view->lcdbuf,"Welcome GolfField");
        
        meberentity->printfInfo(cardNum,rfid_view->lcdbuf2);
        sprintf(write_buf,rfid_view->lcdbuf2);
      
        component->sendData(write_buf);
        //server->writemsg(rfid_view->lcdbuf2);
        rfid_view->updateView("CARDCHECK");
       // std::cout<<rfid_view->lcdbuf2<<std::endl;
       // sprintf(rfid_view->lcdbuf2,meberentity->Card_ID);
        //std::cout<<"Registered Number"<<std::endl;
        //meberentity->printfInfo(52000);
        //meberentity->printfInfo(52001);
      
        
            //  for(int i=0;i<5;i++)
            // { 
            //    // printf("ddd %d",a);
            //     printf(" %x ",*(cardNum+i));

            // }
    }
    else 
    {
        //std::cout<<"Not Registered Member"<<std::endl;
        sprintf(rfid_view->lcdbuf,"Not Registered    ");
        sprintf(rfid_view->lcdbuf2,"Please Regist    ");
        rfid_view->updateView("CARDCHECK");
    }
    break;

    case CARD_REG:

    if((meberentity->FindInfo(cardNum))==1)
    {
        //std::cout<<"It is already used card"<<std::endl;
        sprintf(rfid_view->lcdbuf,"It's already     ");
        sprintf(rfid_view->lcdbuf2,"Registered Card ");
        rfid_view->updateView("CARDCHECK");
        //meberentity->printfInfo(cardNum);

    }
    else
    {  
        sprintf(rfid_view->lcdbuf,"REGISTERING      ");
        sprintf(rfid_view->lcdbuf2,"Use your card");
        rfid_view->updateView("CARDCHECK");
        std::cout<<"REGISTERING"<<std::endl;
        std::cout<<"DO you want to register new Member? [y/n] ";
        std::cin>>command;
        if(strcmp(command,"n")  == 0) return ;
        if(strcmp(command,"y")  == 0) 
        {
        std::cout<<"Please Insert you Name: ";
        std::cin>>command;
        strcpy(temp.name,command);     
        
        std::cout<<"Please Insert you address: ";
        std::cin>>command;
        strcpy(temp.address,command); 

        std::cout<<"Please Insert you phoneNumber: ";
        std::cin>>command;
        strcpy(temp.phoneNumber,command); 


        memcpy(temp.cardNum,cardNum,sizeof(temp.cardNum));
       // temp.id=memeberid;
       temp.id=memeberid+member_add;
        member_add++;
        }

    // temp.id=52000;
    // strcpy(temp.name,"lisunshin");
    // strcpy(temp.address,"11dong 123ho");
    // strcpy(temp.phoneNumber,"222 222 2222");
    // memcpy(temp.cardNum,cardNum,sizeof(temp.cardNum));
        sprintf(rfid_view->lcdbuf,"Resister is done");
        sprintf(rfid_view->lcdbuf2,"                ");
        rfid_view->updateView("CARDCHECK");
        std::cout<<"Register is Done "<<std::endl;
        meberentity->Addinfo(temp);
        break;
    }
    }
}


void GMService::checkName_server(std::string Findstr)
{

     if((meberentity->FindInfo(Findstr))==1)
    {   
        meberentity->printfInfo_server(Findstr,write_buf);
        sprintf(write_mesg,"%s %s","you got member\n\n",write_buf );
        component->sendData(write_mesg);
        //std::cout<<write_buf<<std::endl;
        //component->sendData("member\nPlease type Command:\n");
        component->CompleteSend();
    }
    else
    {
        component->sendData("No member\nPlease type Command:\n\n");
        component->CompleteSend();
    }

}

  void GMService::checkCard_server(int *cardNum)
 {
     if((meberentity->FindInfo(cardNum))==1)
    {   
        meberentity->printfInfo_server(cardNum,write_buf);
        sprintf(write_mesg,"%s %s","you got member\n\n",write_buf );
        component->sendData(write_mesg);
        //std::cout<<write_buf<<std::endl;
        //component->sendData("member\nPlease type Command:\n");
        component->CompleteSend();
    }
    else
    {
        component->sendData("No member\nPlease type Command:\n\n");
        component->CompleteSend();
    }
 }

   void GMService::Delete_member(std::string delstr)
 {

        if(meberentity->DeleteInfo(delstr))
        {
        component->sendData("Delete member\nPlease type Command:\n\n");
        component->CompleteSend();
        }
        else
        {
        component->sendData("Please check member information\nPlease type Command:\n\n");
        component->CompleteSend();
        }
 }