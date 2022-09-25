#ifndef MEMBERENTITY_H
#define MEMBERENTITY_H

#pragma once
#include "MemberInfo.h"
#include <vector>
#include <iostream>
//#include <string>
#include <string.h>
class MemberEntity
{
public:
    MemberEntity();
    ~MemberEntity();
    
    void Loadinfo();
  
    void printfInfo(int index);
    void printfInfo(int *cardNum,char *buf);
    void printfInfo(int *cardNum);
    void printfInfo_server(int *cardNum,char *buf);
    void printfInfo_server(std::string Infostr,char *buf);
    bool FindInfo(std::string Infostr);
    bool FindInfo(int *cardNum);

    void WriteDB();
    
    void Addinfo(MemberInfo Info);


    bool DeleteInfo(std::string Infostr);
    bool DeleteInfo(int *cardNum);
    
    MemberInfo memberInfo;
    std::vector<MemberInfo> InfoList;

    
    
    int Card_ID;
    
    FILE *fpData;
private:
   
};

#endif