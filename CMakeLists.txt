cmake_minimum_required(VERSION 3.0.0)

project(GM_tcp)


add_executable(${PROJECT_NAME}
    ./src/main.cpp

    ./src/app/Listener/Listener.cpp
    ./src/app/View/RFID_View/RFID_View.cpp
    ./src/app/Control/Control.cpp
   
    ./src/app/Entity/MemberEntity.cpp
    
    ./src/app/Service/Service.cpp
    ./src/app/Service/GMService/GMService.cpp
    
   
    ./src/hw/rfid/CardReader.cpp
    ./src/hw/rfid/mfrc522.cpp
    ./src/hw/spi/SPI.cpp
    ./src/hw/GM/GM.cpp
    ./src/hw/Button/ManageButton/ManageButton.cpp
    ./src/hw/Button/Button.cpp
    ./src/hw/TCPServer/TCPServer.cpp
    ./src/hw/TCPServer/ComDev.cpp
    ./src/hw/I2C/I2C.cpp
    ./src/hw/LCD/LCD.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    

     ./src/app/Listener

     ./src/app/View/RFID_View

     ./src/app/Entity

     ./src/app/Device_Data

     ./src/app/Control

     ./src/app/Service
     ./src/app/Service/GMService

     ./src/hw/rfid
     ./src/hw/spi
     ./src/hw/GM
     ./src/hw/Button/ManageButton
     ./src/hw/Button
     ./src/hw/TCPServer
     ./src/hw/I2C
     ./src/hw/LCD
     
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

