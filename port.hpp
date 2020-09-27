#ifndef __PORT_H
#define __PORT_H
#include "types.hpp"

struct Port
{
    protected:
        uint16_t portnumber;
        Port(uint16_t portnumber);
        ~Port();
};

struct Port8Bit: public Port
{
    Port8Bit(uint16_t portnumber);
    ~Port8Bit();
    virtual void Write(uint8_t data);
    virtual uint8_t Read();
};

struct Port8BitSlow: public Port8Bit
{
    Port8BitSlow(uint16_t portnumber);
    ~Port8BitSlow();
    virtual void Write(uint8_t data);
};

struct Port16Bit : public Port
{
    Port16Bit(uint16_t portnumber);
    ~Port16Bit();
    virtual void Write(uint16_t data);
    virtual uint16_t Read();
};

struct Port32Bit : public Port
{
    Port32Bit(uint32_t portnumber);
    ~Port32Bit();
    virtual void Write(uint32_t data);
    virtual uint32_t Read();
};

#endif //__PORT_H