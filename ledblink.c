#include <LPC17xx.h>
void delay(unsigned long int x)
{
int i;
for(i=0;i<x;i++);
}
int main()
{
SystemInit();
LPC_GPIO1 -> FIOMASK3=0xDF;//11011111
LPC_GPIO1 -> FIODIR3=0x20;//00100000
while(1)
{
LPC_GPIO1-> FIOSET3=0x20;
delay(500000);
LPC_GPIO1-> FIOCLR3=0x20;
delay(500000);
}
}