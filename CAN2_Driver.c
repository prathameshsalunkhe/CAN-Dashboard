#include <LPC21xx.H>

void can2_init(void)
{
	PINSEL1|=0x00014000;
	VPBDIV=1;
	C2MOD=1;
	C2BTR=0x001C001D;
	AFMR=2;
	C2MOD=0;	
}
