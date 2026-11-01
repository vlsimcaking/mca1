#include <reg51.h>

sbit BUTTON1 = P0^0;
sbit BUTTON2 = P0^1;

sbit RELAY = P3^6;
sbit BUZZER = P3^7;

void delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void left_to_right(void)
{
    unsigned char i;

    for(i = 0; i < 8; i++)
    {
        P2 = (1 << i);
        delay_ms(200);
    }
}

void right_to_left(void)
{
    unsigned char i;

    for(i = 0; i < 8; i++)
    {
        P2 = (0x80 >> i);
        delay_ms(200);
    }
}

void main()
{
    P2 = 0x00;
    RELAY = 0;
    BUZZER = 0;

    while(1)
    {
        if(BUTTON1 == 0)
        {
            RELAY = 1;
            BUZZER = 1;

            left_to_right();

            P2 = 0x00;
        }

        if(BUTTON2 == 0)
        {
            RELAY = 0;
            BUZZER = 0;

            right_to_left();

            P2 = 0x00;
        }
    }
}