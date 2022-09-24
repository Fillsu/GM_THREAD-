#include "ManageButton.h"

ManageButton::ManageButton(int pin,std::string str):Button(pin)
{
ButtonData.name=str;
}

ManageButton::~ManageButton()
{

}

bool ManageButton::checkButton()
{
    if (getState() == RELEASE_ACTIVE)
        return true;
    
    return false;

}


Device_Data ManageButton:: getButtonData()
{



//mfrc522_get_card_serial(RFIDData);
//ButtonData.name="cardreadername";
ButtonData.number.clear();
// for (const auto ndata:RFIDData)
// {ButtonData.number.push_back(1);
// }
ButtonData.number.push_back(1);
return ButtonData;

}
