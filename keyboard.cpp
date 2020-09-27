#include "keyboard.hpp"
extern void print(char* s);

KeyboardDriver::KeyboardDriver(InterruptManager* manager) :
    InterruptHandler(0x21, manager),
    dataport(0x60),
    commandport(0x64)
{
    while(commandport.Read() & 0x1)
    {
        dataport.Read();
    }
    commandport.Write(0xAE);
    commandport.Write(0x20);
    uint8_t status = (dataport.Read() | 1) & ~0x10;
    commandport.Write(0x60);
    dataport.Write(status);

    dataport.Write(0xF4);
};

KeyboardDriver::~KeyboardDriver()
{

};

uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp)
{
    uint8_t key = dataport.Read();
    if (key < 0x80)
    {
        switch (key)
        {
            case 0xFA: case 0xC5: case 0x45: break;
            default:
                char* keypress = "0x00";
                char* hex = "0123456789ABCDEF";

                keypress[2] = hex[(key >> 4) & 0xf];
                keypress[3] = hex[(key)& 0xf];

                print(keypress);
                print("\n");
                break;
        }
    }

    return esp;
}