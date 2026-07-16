#include <LPC17xx.h>
void delay(unsigned long int x)
{
int i;
for(i=0;i<x;i++);
}
int main()
{
SystemInit();
LPC_GPIO0 -> FIOMASK1=0xF0;
LPC_GPIO0 -> FIODIR1=0x0F;
while(1)
{
LPC_GPIO0-> FIOSET1=0x0F;
delay(0x500000);
LPC_GPIO0-> FIOCLR1=0x0F;
delay(0x500000);
}
}