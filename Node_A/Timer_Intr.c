#include <lpc21xx.h>
#include "header.h"
u32 timer0=0;
u32 timer1=0;

void timer0_Handler(void)__irq
{
        timer0=1;
        T0IR=1;//Intrr Reg
        VICVectAddr=0;
}
void config_vic_for_timer0()
{
        VICIntSelect=0;
        VICVectCntl0=4|(1<<5);
        VICVectAddr0=(u32)timer0_Handler;
        VICIntEnable=(1<<4);
}
void timer0_config()
{
        T0PC=0;
        T0PR=1000000-1;    	
        T0TC=0;
        T0MR0=3; //Match Reg to reset TC
        T0MCR=3;// Match Control Register
        T0TCR=1;//Enable
}
////////////////////////////////////////////
void timer1_Handler(void)__irq
{
        timer1=1;
        T1IR=1; //Intr.Reg
        VICVectAddr=0;
}
void config_vic_for_timer1()
{
        VICIntSelect=0;
        VICVectCntl1=5|(1<<5);
        VICVectAddr1=(u32)timer1_Handler;
        VICIntEnable=(1<<5);
}
void timer1_config()
{
        T1PC=0;
        T1PR=15000000-1;
        T1TC=0;
        T1MR0=3;
        T1MCR=3;
        T1TCR=1;
}


