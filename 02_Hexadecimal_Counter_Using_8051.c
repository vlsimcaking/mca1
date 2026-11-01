#include <reg51.h>

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 500; i++)
        for(j = 0; j < 120; j++);
}

void main()
{
    unsigned char count;

    while(1)
    {
        for(count = 0; count <= 0x0F; count++)
        {
            P2 = count;
            delay();
        }
    }
}