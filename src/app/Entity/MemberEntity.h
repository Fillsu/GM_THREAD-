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
    void printfInfo(int *cardNum);
  
    bool FindInfo(std::string Infostr);
    bool FindInfo(int *cardNum);

    void WriteDB();
    
    void Addinfo(MemberInfo Info);


    bool DeleteInfo(std::string Infostr);
    bool DeleteInfo(int *cardNum);
    
    MemberInfo memberInfo;
    std::vector<MemberInfo> InfoList;


    FILE *fpData;
private:
    
};

#endif