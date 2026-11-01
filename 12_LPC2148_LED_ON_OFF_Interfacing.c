#include <lpc214x.h>

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 500; i++)
        for(j = 0; j < 1275; j++);
}

int main()
{
    PINSEL2 = 0x00000000;

    IODIR1 = 0xFF000000;

    while(1)
    {
        IOSET1 = 0xFF000000;
        delay();

        IOCLR1 = 0xFF000000;
        delay();
    }
}