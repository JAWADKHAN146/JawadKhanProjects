#include <LPC17xx.h>
void delay(long int x)
{
int i;
for(i=0;i<x;i++);
}
int main()
{
unsigned char cmd[]={0x38,0x0E,0x06,0x01,0x80};
unsigned char msg1[]="JAWADKHAN";
unsigned char msg2[]="PESU";
unsigned char i;
//switch
LPC_GPIO0 -> FIOMASK3 =0xF7;//11110111
LPC_GPIO0 -> FIODIR3 =0xF7;//11110111
var=LPC_GPIO0 ->FIOPIN3=0x08;//00001000
//ENABLE AND DIR FOR PIN 8,9,10
LPC_GPIO1 -> FIOMASK1=0xF8;
LPC_GPIO1 -> FIODIR1=0x07;
//ENABLE AND DIR PIN 0-7
LPC_GPIO2 -> FIOMASK0=0x00;
LPC_GPIO2 -> FIODIR0=0xFF;
//Command
LPC_GPIO1 -> FIOCLR1=0x01;//RS=0
LPC_GPIO1 -> FIOCLR1=0x02;//R/W=0
if((var>>3)==0x01)
{
for(i=0;i<5;i++)
{
LPC_GPIO2 -> FIOPIN0=cmd[i];
LPC_GPIO1 -> FIOSET1=0x04;//EN=1
delay(500);
LPC_GPIO1 -> FIOCLR1=0x04;//EN=1
delay(50000);
}
//DISPLAY
LPC_GPIO1 -> FIOSET1=0x01;//RS=1
for(i=0;msg1[i]!='\0';i++)
{
LPC_GPIO2 -> FIOPIN0=msg1[i];
	LPC_GPIO1 -> FIOSET1=0x04;//EN=1
delay(500);
LPC_GPIO1 -> FIOCLR1=0x04;//EN=0
delay(50000);
}
   // MOVE CURSOR TO LINE 2 POSITION 1
    LPC_GPIO1->FIOCLR1=0x01; // RS=0
    LPC_GPIO2->FIOPIN0=0xC0;

    LPC_GPIO1->FIOSET1=0x04; // EN=1
    delay(500);
    LPC_GPIO1->FIOCLR1=0x04; // EN=0

    delay(50000);

    // DISPLAY SECOND LINE
  LPC_GPIO1->FIOSET1=0x01; // RS=1

    for(i=0;msg2[i]!='\0';i++)
    {
        LPC_GPIO2->FIOPIN0=msg2[i];

        LPC_GPIO1->FIOSET1=0x04; // EN=1
        delay(500);
        LPC_GPIO1->FIOCLR1=0x04; // EN=0

        delay(50000);
    }
else
{
  LPC_GPIO1->FIOCLR1=0x01; // RS=0
LPC_GPIO2->FIOPIN0=0X01

}