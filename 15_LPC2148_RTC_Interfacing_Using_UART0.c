#include <lpc214x.h>
#include <stdio.h>

void delay(unsigned int time)
{
    volatile unsigned int i, j;

    for(i = 0; i < time; i++)
        for(j = 0; j < 2000; j++);
}

void UART0_Init(void)
{
    PINSEL0 = 0x00000005;

    U0LCR = 0x83;

    U0DLL = 0x86;
    U0DLM = 0x01;

    U0FDR = 0xC1;

    U0LCR = 0x03;
}

void UART0_TxChar(unsigned char ch)
{
    while((U0LSR & 0x20) == 0);

    U0THR = ch;
}

void UART0_TxString(char *str)
{
    while(*str != '\0')
    {
        UART0_TxChar(*str);
        str++;
    }
}

void RTC_Init(void)
{
    CCR = 0x00;

    ILR = 0x03;

    CIIR = 0x00;

    CCR = 0x11;
}

void RTC_SetTime(void)
{
    HOUR = 10;
    MIN = 30;
    SEC = 1;

    DOM = 14;
    MONTH = 10;
    YEAR = 2026;

    DOW = 3;

    DOY = 287;
}

int main(void)
{
    char buffer[50];

    UART0_Init();

    RTC_Init();

    RTC_SetTime();

    UART0_TxString("\r\nRTC INTERFACING WITH LPC2148\r\n");
    UART0_TxString("--------------------------------\r\n");

    while(1)
    {
        sprintf(buffer, "Time: %02d:%02d:%02d\r\n",
                HOUR, MIN, SEC);

        UART0_TxString(buffer);

        sprintf(buffer, "Date: %02d/%02d/%04d\r\n",
                DOM, MONTH, YEAR);

        UART0_TxString(buffer);

        UART0_TxString("------------------------------\r\n");

        delay(500);
    }
}