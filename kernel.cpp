
void printf(char* s)
{
    unsigned short* VideoMemory = (unsigned short*)0xb8000;
    for(int i = 0; s[i] != '\0'; ++i)
    {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | s[i];

    }
}

extern "C" void entry(void* multiboot_struct, unsigned int magicnumber)
{
    printf("Hello World!\n");
    while(1);
}