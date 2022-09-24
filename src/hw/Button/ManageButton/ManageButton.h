#ifndef MANAGEBUTTON_H
#define MANAGEBUTTON_H

#pragma once
#include "Button.h"
#include "Device_Data.h"
#include <string>
#include "mfrc522.h"
class ManageButton:public Button
{
public:
    ManageButton(int pin,std::string str);
    ~ManageButton();
    bool checkButton();
    Device_Data getButtonData();
     Device_Data ButtonData;
private:

};

#endif