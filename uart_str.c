#include <LPC17xx.h>
void delay(unsigned int x)
{
	int i;
	for(i=0;i<x;i++);
}
void uart_init(void)
{
//pconp is enabled by default for uart0 and pclksel is taken as default value
LPC_UART0->LCR=0X00000083;
LPC_UART0->DLM=0X00000000;
LPC_UART0->DLL=0X00000075;
LPC_UART0->FDR=0X00000010;
LPC_UART0->LCR=0X00000003;
}
int main()
{
unsigned char str1[]="ARM CORTEX M3 ", i;
SystemInit();
LPC_PINCON->PINSEL0|=0X00000050;
uart_init();
for(i=0;str1[i]!='\0';i++)
{
LPC_UART0->THR=str1[i];
while((LPC_UART0->LSR & 0X20)!=0X20);
delay(50000);
}
}