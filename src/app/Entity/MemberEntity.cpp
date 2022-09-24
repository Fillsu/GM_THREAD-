#include "MemberEntity.h"
#include "ComDev.h"

MemberEntity::MemberEntity()
{
//fpData=fopen("memberLists.bin","r+");
    Loadinfo();
    //std::cout<<InfoList.size()<<std::endl;
}

MemberEntity::~MemberEntity()
{

}

void MemberEntity::Loadinfo()
{   
    fpData=fopen("memberLists.bin","r+");
    if(fpData==NULL)
    {
        fprintf(stderr,"FILE open error");
        //std::cout<<"FILE open error"<<std::endl;
        return;
    }

    while(fread(&memberInfo,sizeof(MemberInfo),1,fpData))
    { 
        InfoList.push_back(memberInfo);
    }
//전부 로딩후 닫아주겠다.
fclose(fpData);
}

void MemberEntity::printfInfo(int index)
{  
// std::cout<< InfoList[1000].id <<std::endl;
// std::cout<<InfoList[1000].address<<std::endl;
// std::cout<< InfoList[1000].name<<std::endl;
// std::cout<< InfoList[1000].cardNum<<std::endl;
    if(index > (int)InfoList.size())
    {
        fprintf(stderr,"Out of Range Index\n");
    }
    //std::cout<<InfoList[index].id<<std::endl;
    printf("%04d, %s, %s, %s, %0x-%0x-%0x-%0x-%0x\n",
    InfoList[index].id,
    InfoList[index].name,
    InfoList[index].address,
    InfoList[index].phoneNumber,
    InfoList[index].cardNum[0],
    InfoList[index].cardNum[1],
    InfoList[index].cardNum[2],
    InfoList[index].cardNum[3],
    InfoList[index].cardNum[4]
    );

}

void MemberEntity:: Addinfo(MemberInfo Info)
{
InfoList.push_back(Info);

}

bool MemberEntity:: DeleteInfo(std::string Infostr)
{
     std::vector<MemberInfo>::iterator pItr;
    pItr=InfoList.begin();//맨 앞의 해당주소를 받는다. 
    
    for(pItr;pItr!=InfoList.end();pItr++)
    {
        if(strcmp(pItr->name,Infostr.c_str())==0)
        {
            InfoList.erase(pItr);
            return true;
        }
    } 
    return false;
}


bool MemberEntity::DeleteInfo(int *cardNum)
{
    std::vector<MemberInfo>::iterator pItr;
    pItr=InfoList.begin();//맨 앞의 해당주소를 받는다. 
    
    for(pItr;pItr!=InfoList.end();pItr++)
    {
        if(memcmp(pItr->cardNum,cardNum,sizeof(pItr->cardNum))==0)
        {
            InfoList.erase(pItr);
            return true;
        }
    } 
    return false;
}


bool MemberEntity::FindInfo(std::string Infostr)
{

    for(const auto &member:InfoList)
    {
        if(strcmp(member.name,Infostr.c_str())==0)
        {
            //printfInfo(member.id);
            return true ;
            
        }
    }
    return false ;
}



bool MemberEntity::FindInfo(int *cardNum)
{
    for(const auto &member:InfoList)
    {
        if(memcmp(member.cardNum,cardNum,sizeof(member.cardNum))==0)
        {
            //printfInfo(member.id);
            Card_ID=member.id;
            return true ;
            
        }
    }
    return false ;

}


void MemberEntity::printfInfo(int *cardNum,char *buf)
{//char a[3]="dd";
    for(const auto &member:InfoList)
    {
        if(memcmp(member.cardNum,cardNum,sizeof(member.cardNum))==0)
        {   
            //std::cout<<a<<std::endl;
            std::cout<<InfoList[member.id].name<<std::endl;
            sprintf(buf,"%s Member     ",InfoList[member.id].name);
           // printfInfo(member.id);
                        
        }
    }

}

void MemberEntity::printfInfo(int *cardNum)
{
    for(const auto &member:InfoList)
    {
        if(memcmp(member.cardNum,cardNum,sizeof(member.cardNum))==0)
        {
        
            
            printfInfo(member.id);
                        
        }
    }

}


void MemberEntity::WriteDB()
{
    fpData=fopen("memberLists2.bin","w+");
    //InfoList
    for(const auto &member:InfoList)
    {  
        fwrite(&member,sizeof(MemberInfo),1,fpData);
        
    }
    fclose(fpData);
}