#include "RFID_View.h"

RFID_View::RFID_View()
{
lcd=new LCD(new I2C("/dev/i2c-1", 0x27));
}

RFID_View::~RFID_View()
{

}

void RFID_View::updateView(std::string rfidstr)
{
//std::cout<<"LCD "<<std::endl;
lcd->WriteStringXY(0,0,"           ");
lcd->WriteStringXY(0,0,lcdbuf);
    // if(rfidstr=="CARDCHECK")
    // {       

    //     lcd->WriteStringXY(0,0,lcdbuf);

    // }
}

            // std::cout<<" "<<std::endl;
            // for(int i=0;i<5;i++)
            // {  
                
                
            //    // printf("ddd %d",a);
            //     printf(" %x ",*(RFIDData+i));

            // }
    // for(const auto ndata:data->number)
    //   {
    
    // std::cout<<ndata<<" ";
    //    }

    // std::cout<<std::endl;