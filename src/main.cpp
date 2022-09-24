#include <iostream>

#include <string>
#include "mfrc522.h"
#include "Listener.h"
#include "wiringPi.h"
#include "RFID_View.h"
#include "GM.h"
#include "MemberEntity.h"
#include <cstring>

int main(void)
{
GM *gm1=new GM();
gm1->GM_Run();
// mfrc522 rfid(new SPI(10, 3000000));

//RFID_View rfidview1;

//Listener listener(&rfid,&rfidview1);
//std::cout<<"dd"<<std::endl;
//std::cout<<" "<<std::endl;
MemberEntity a;
MemberInfo testMember;
int testnumer[5]={100,100,100,100,100};
int testnumer0x[5]={0xc2,0x65,0xe5,0x8e,0xe9};
//MemberInfo testMember={100000,"testname","ad ress","111 111 1111","1,1,1,1,1"};
strcpy(testMember.address,"ad ress");

testMember.cardNum[0]=100;
testMember.cardNum[1]=100;
testMember.cardNum[2]=100;
testMember.cardNum[3]=100;
testMember.cardNum[4]=100;
testMember.id=52000;
strcpy(testMember.name,"hong gile dong");
strcpy(testMember.phoneNumber,"111-111-1111");

//a.Addinfo(testMember);

if(a.FindInfo("hong gile dong")==1)
{
    std::cout<<"find the name"<<std::endl;
    a.printfInfo(52000);
   //  a.printfInfo("dd",testnumer0x);//뭐함?? a.가 왜 없음
   // printf("find the name");
}

//a.DeleteInfo("hong gile dong");
//a.DeleteInfo(testnumer);
if(a.FindInfo(testnumer)==1)
{
    std::cout<<"find the number"<<std::endl;
  
}
else 
{
    std::cout<<"cannot find"<<std::endl;
}
//a.WriteDB();



}
// int main(void)
// {
//     mfrc522 rfid(new SPI(10, 3000000));
//     uint8_t byte;
//     uint8_t str[MAX_LEN];
//     byte = 0x55; // just to check that byte is getting loaded and printed
//     delay(1500);

//     // check version of the reader
//     byte = rfid.mfrc522_read(VersionReg);

//     printf("ver --> %0x\n", byte);
//     if (byte == 0x92)
//     {
//         printf("MIFARE RC522v2\r\n");
//         printf("Detected\r\n");
//     }
//     else if (byte == 0x91 || byte == 0x90)
//     {
//         printf("MIFARE RC522v1\r\n");
//         printf("Detected\r\n");
//     }
//     else
//     {
//         printf("No reader found\r\n");
//     }

//     while (1)
//     {
//         byte = rfid.mfrc522_request(PICC_REQALL, str);
//         printf("byte-->%d ", byte);
//         if (byte == CARD_FOUND)
//         {
//             for (int i = 0; i < MAX_LEN; i++)
//                 str[i] = ' ';
//             byte = rfid.mfrc522_get_card_serial(str);

//             for (int i = 0; i < 5; i++)
//                 printf("%02x ", str[i]);
//             printf("\n");
//         }
//         delay(1000);
//         printf("hihi\n");
//     }
// }
