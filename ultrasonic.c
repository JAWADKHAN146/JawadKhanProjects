#include <LPC17xx.h>
void initTimer0(void)
{
	//pconp and pclksel is not required for timer/counter 0,1
	LPC_TIM0->CTCR=0x0;//setting to timer mode
	LPC_TIM0->PR=(18-1);//PRESCALE REGISTER COUNT
	LPC_TIM0->TCR=0x02;//RESTING TIMER
}
void delayUS(unsigned int microsecond)//using timer0
{
	LPC_TIM0->TCR=0x02;//RESETTING TIMER
	LPC_TIM0->TCR=0X01;//TIMER IS ENBLED
	while(LPC_TIM0->TC<  microsecond)
	{
	}
	LPC_TIM0->TCR=0x00;
}
int main()
{
	
	unsigned int time;
	float dis;
	//---------buzzer-------P0.1---------------
	//LPC_GPIO0->FIOMASK0=0XFE;
	//LPC_GPIO0->FIODIR0=0X01;
	//--------LED-----------P1.29---------------
	LPC_GPIO1->FIOMASK3=0XDF; 
	LPC_GPIO1->FIODIR3=0X20; 
	LPC_GPIO1->FIOCLR3=0X20;
	//---------Trig(P0.21)--Echo(P0.22)-----------
	LPC_GPIO0->FIOMASK2=0x9F;//10011111
	LPC_GPIO0->FIODIR2=0x20;//001000000
	while(1)
	{ 
		LPC_GPIO0->FIOCLR2 = 0x20;
    delayUS(2);
		LPC_GPIO0->FIOSET2=0X20;
		delayUS(10);
		LPC_GPIO0->FIOCLR2=0X20;
		while((LPC_GPIO0->FIOPIN2&0x40)==0);
		LPC_TIM0->TCR=0x02;//RESETTING TIMER
		LPC_TIM0->TCR=0X01;//TIMER IS ENBLED
		while((LPC_GPIO0->FIOPIN2 &0x40)!=0);
		LPC_TIM0->TCR = 0x00;
		time = LPC_TIM0->TC;
		dis = (time * 0.0343)/2;
			  if(dis<=5.0f)
			  {   //LPC_GPIO0->FIOSET0=0X01;
			  		LPC_GPIO1->FIOSET3=0X20;
		delayUS(100000);
	  //LPC_GPIO0->FIOCLR0=0X01;
		LPC_GPIO1->FIOCLR3=0X20;
		delayUS(100000);
		}
				else
				{
					//LPC_GPIO0->FIOCLR0=0X01;
					LPC_GPIO1->FIOCLR3=0X20;
				}
	}
}
