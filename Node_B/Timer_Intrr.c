#include <lpc21xx.h>
int timer1=0;
int timer2=0;
extern unsigned int sflag1;
extern unsigned int sflag2;

void timer1_handler() __irq
{
	timer1=timer1^1;
	timer2=timer2^1;

	T1IR=1;
	VICVectAddr=0;
}
void config_vic_for_timer1(void){
	VICIntSelect=0;
	VICVectCntl4=5|(1<<5);
	VICVectAddr4=(unsigned int)timer1_handler;
	VICIntEnable=1<<5;
}
void timer1_config(){
	T1PC=0;
	T1PR=60000-1;
	T1TC=0;
	T1MR0=1000;
	T1MCR=3;
	T1TCR=1;
}


