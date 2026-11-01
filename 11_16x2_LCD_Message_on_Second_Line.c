#include <reg51.h>

sbit RS = P2^2;
sbit RW = P2^1;
sbit EN = P2^0;

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
        for(j = 0; j < 1275; j++);
}

void command(unsigned char cmd)
{
    P1 = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

void data(unsigned char ch)
{
    P1 = ch;
    RS = 1;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

void main()
{
    command(0x38);
    command(0x0C);
    command(0x01);
    command(0x06);

    command(0xC0);

    data('W');
    data('e');
    data('l');
    data('c');
    data('o');
    data('m');
    data('e');

    while(1);
}