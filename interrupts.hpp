#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H
#include "types.hpp"
#include "port.hpp"
#include "gdt.hpp"

struct InterruptManager
{
    static uint32_t handleInterrupt(uint8_t interruptNumber, uint32_t esp);
    static void HandleInterruptRequest0x00();
    static void HandleInterruptRequest0x01();
    static void IgnoreInterruptRequest();
    void Activate();

    InterruptManager(GlobalDescriptorTable* gdt);
    ~InterruptManager();

    protected:
        struct GateDescriptor
        {
            uint16_t handlerAddressLowBits;
            uint16_t gdt_codeSegmentSelector;
            uint8_t reserved;
            uint8_t access;
            uint16_t handlerAddressHighBits;
        }__attribute__((packed));

        struct InterruptDescriptorTablePointer
        {
            uint16_t size;
            uint32_t base;
        } __attribute__((packed));
    static GateDescriptor interruptDescriptorTable[256];
    static void SetInterruptDescriptorTableEntry(
        uint8_t interruptNumber,
        uint16_t codeSegmentSelectorOffset,
        void (*handler)(),
        uint8_t DescriptorPrivilegeLevel,
        uint8_t DescriptorType
    );


    Port8BitSlow picMasterCommand;
    Port8BitSlow picMasterData;
    Port8BitSlow picSlaveCommand;
    Port8BitSlow picSlaveData;
};


#endif //__INTERRUPTS_H