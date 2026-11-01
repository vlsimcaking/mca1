#include <reg51.h>

sbit D1 = P3^2;
sbit D2 = P3^3;

unsigned char code seg[10] =
{
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 10; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    unsigned char i, j;

    while(1)
    {
        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                D1 = 1;
                D2 = 0;
                P2 = seg[i];
                delay();

                D1 = 0;
                D2 = 1;
                P2 = seg[j];
                delay();
            }
        }
    }
}