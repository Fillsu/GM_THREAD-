#include "GMService.h"


GMService::GMService(TCPServer *server):meberentity(new MemberEntity)
{
 this->server=server;
 GMState=CARD_READ;
 memeberid=meberentity->InfoList.size();
 member_add=0;
 rfid_view=new RFID_View();
 //component=new ComDev();
 

}

GMService::~GMService()
{

}


 void GMService::updateService(std::string GMstr)
{   // std::cout<<" "<<std::endl;
   
   if(GMstr=="search")
    {   
        sprintf(write_buf,"you got search");
        server->writemsg(write_buf);
    
    }

       if(GMstr=="wrong")
    {   
        sprintf(write_buf,"you got wrong");
        server->writemsg(write_buf);
    
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
        server->writemsg(rfid_view->lcdbuf2);
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
        std::cout<<"Not Registered Member"<<std::endl;
        sprintf(rfid_view->lcdbuf,"Not Registered    ");
        sprintf(rfid_view->lcdbuf2,"Please Regist    ");
        rfid_view->updateView("CARDCHECK");
    }
    break;

    case CARD_REG:

    if((meberentity->FindInfo(cardNum))==1)
    {
        std::cout<<"It is already used card"<<std::endl;

        meberentity->printfInfo(cardNum);

    }
    else
    {
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