
void printf(char* s)
{
    unsigned short* VideoMemory = (unsigned short*)0xb8000;
    for(int i = 0; s[i] != '\0'; ++i)
    {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | s[i];

    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
    {
        (*i)();
    }
}

extern "C" void entry(const void* multiboot_struct, unsigned int magicnumber)
{
    printf("Hello World!\n");
    while(1);
}