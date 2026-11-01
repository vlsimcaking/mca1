#include <reg51.h>

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 200; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    while(1)
    {
        P2 = 0x01;
        delay();
        P2 = 0x02;
        delay();
        P2 = 0x04;
        delay();
        P2 = 0x08;
        delay();
        P2 = 0x10;
        delay();
        P2 = 0x20;
        delay();
        P2 = 0x40;
        delay();
        P2 = 0x80;
        delay();
    }
}