#include "GMService.h"

GMService::GMService():meberentity(new MemberEntity)
{
 GMState=CARD_READ;
 memeberid=meberentity->InfoList.size();
 member_add=0;
 rfid_view=new RFID_View();
}

GMService::~GMService()
{

}

 void GMService::updateService(std::string GMstr)
{   // std::cout<<" "<<std::endl;
    switch (GMState)
    {
    case CARD_READ:
    if(GMstr=="MODECHECK")
    {   //int a=0;
        GMState=CARD_REG;
       // sprintf(rfid_view->lcdbuf,"REGISTERING");
      //  rfid_view->updateView("CARDCHECK");
      //  std::cout<<"REGISTERING"<<std::endl;
       //printf("REGISTERING");

        
        //std::cout<<command<<std::endl;
    }
    break;
    case CARD_REG:
    if(GMstr=="MODECHECK")
    {
        GMState=CARD_READ;
       // std::cout<<"READING"<<std::endl;
      // sprintf(rfid_view->lcdbuf,"READING");
      //  rfid_view->updateView("CARDCHECK");
      //  printf("READING");
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
        
        printf("Registered Number\n");

        //std::cout<<"Registered Number"<<std::endl;
        //meberentity->printfInfo(52000);
        //meberentity->printfInfo(52001);
        meberentity->printfInfo(cardNum);
            //  for(int i=0;i<5;i++)
            // { 
            //    // printf("ddd %d",a);
            //     printf(" %x ",*(cardNum+i));

            // }
    }
    else 
    {
        std::cout<<"Not Registered Number"<<std::endl;
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
       temp.id=52001;
        member_add++;
        }

    // temp.id=52000;
    // strcpy(temp.name,"lisunshin");
    // strcpy(temp.address,"11dong 123ho");
    // strcpy(temp.phoneNumber,"222 222 2222");
    // memcpy(temp.cardNum,cardNum,sizeof(temp.cardNum));
        std::cout<<"Register is Done "<<std::endl;
        meberentity->Addinfo(temp);
        break;
    }
    }
}