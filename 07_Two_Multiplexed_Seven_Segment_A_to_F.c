#include <reg51.h>

sbit D1 = P3^2;
sbit D2 = P3^3;

unsigned char code seg[6] =
{
    0x77,  // A
    0x7C,  // b
    0x39,  // C
    0x5E,  // d
    0x79,  // E
    0x71   // F
};

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 10; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    unsigned char i;

    while(1)
    {
        for(i = 0; i < 6; i++)
        {
            D1 = 1;
            D2 = 0;
            P2 = 0x3F;
            delay();

            D1 = 0;
            D2 = 1;
            P2 = seg[i];
            delay();
        }
    }
}