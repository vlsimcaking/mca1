#include <reg51.h>

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 500; i++)
        for(j = 0; j < 120; j++);
}

void main()
{
    while(1)
    {
        P2 = 0x77;  // A
        delay();
        P2 = 0x7C;  // b
        delay();
        P2 = 0x39;  // C
        delay();
        P2 = 0x5E;  // d
        delay();
        P2 = 0x79;  // E
        delay();
        P2 = 0x71;  // F
        delay();
    }
}