#include <LPC17xx.h>

void delay(unsigned long int x)
{
    unsigned long int i;
    for(i = 0; i < x; i++);
}
int main()
{
    unsigned char count;
    SystemInit();
    LPC_GPIO0->FIOMASK1 = 0xF0;
    LPC_GPIO0->FIODIR1  = 0x0F;

    while(1)
    {
        for(count = 0; count < 16; count++)
        {
            LPC_GPIO0->FIOCLR1 = 0x0F;
            LPC_GPIO0->FIOSET1 = count;

            delay(0x500000);
        }
    }
}