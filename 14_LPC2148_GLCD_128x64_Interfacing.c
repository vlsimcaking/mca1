#include <lpc214x.h>

#define LCD_PORT 0x00FF0000
#define EN       (1<<10)
#define RS       (1<<25)
#define CS1      (1<<26)
#define CS2      (1<<27)
#define GRST     (1<<24)
#define RW       (1<<11)
#define LCD_SHIFT 16

const unsigned char LED_ON[1024] =
{
    0x00
};

void delay(unsigned int time)
{
    int i, j;

    for(i = 0; i < time; i++)
        for(j = 0; j < 50; j++);
}

void ldelay(unsigned int time)
{
    int i, j;

    for(i = 0; i < time; i++)
        for(j = 0; j < 5000; j++);
}

void LCD_strobe(void)
{
    IO0SET = EN;
    delay(5);
    IO0CLR = EN;
    delay(5);
}

void GLCD_data(unsigned char ch)
{
    IO1CLR = LCD_PORT;
    IO1SET = (ch << LCD_SHIFT);
    IO1SET = RS;
    LCD_strobe();
}

void GLCD_cmd(unsigned char ch)
{
    IO1CLR = LCD_PORT;
    IO1SET = (ch << LCD_SHIFT);
    IO1CLR = RS;
    LCD_strobe();
}

void GLCD_init(void)
{
    int i;

    PINSEL0 = 0;
    PINSEL1 = 0;
    PINSEL2 = 0;

    IODIR0 = EN | RW;
    IODIR1 = LCD_PORT | RS | CS1 | CS2 | GRST;

    IO1CLR = LCD_PORT;
    IO1SET = GRST | CS1 | CS2;

    IO0CLR = RW | EN;
    IO1CLR = RS;

    for(i = 0; i < 3; i++)
    {
        GLCD_cmd(0x3F);
        GLCD_cmd(0x40);
        GLCD_cmd(0xB8);
    }
}

void GLCD_disp(const unsigned char *temp1)
{
    int i, j;

    for(i = 0; i < 8; i++)
    {
        IO1SET = CS1;
        IO1CLR = CS2;

        GLCD_cmd(0xB8 | i);
        GLCD_cmd(0x40);

        for(j = 0; j < 64; j++)
            GLCD_data(temp1[i * 128 + j]);

        IO1CLR = CS1;
        IO1SET = CS2;

        GLCD_cmd(0xB8 | i);
        GLCD_cmd(0x40);

        for(j = 64; j < 128; j++)
            GLCD_data(temp1[i * 128 + j]);
    }
}

int main(void)
{
    GLCD_init();

    ldelay(4000);

    while(1)
    {
        GLCD_disp(LED_ON);
        ldelay(2000);
    }
}