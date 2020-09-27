#ifndef __KEYBOARD__H
#define __KEYBOARD_H
#include "interrupts.hpp"

struct KeyboardDriver : public InterruptHandler
{
    KeyboardDriver(InterruptManager* manager);
    ~KeyboardDriver();
    virtual uint32_t HandleInterrupt(uint32_t esp);

    private:
        Port8Bit dataport;
        Port8Bit commandport;
    
};

#endif // __KEYBOARD_H