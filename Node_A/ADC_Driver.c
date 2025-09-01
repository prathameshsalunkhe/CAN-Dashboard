#include <LPC21xx.H>
#include "header.h"
#define DONE ((ADDR>>31)&1)
void adc_init(void)
{
	PINSEL1=PINSEL1|0x15400000;	 //0.27,0.28,0.9,0.30  as AIN
	ADCR=0x00200400; //clk and cancel powerdown mode
}
					  	
u32 adc_read(u8 ch_num)
{
	u32 result=0;
	ADCR=ADCR|(1<<ch_num); //select channel
	ADCR=ADCR|(1<<24);	 //start ADC
	while(DONE==0); //Monitor done flag
	ADCR=ADCR^(1<<24);  //stop ADC
	ADCR=ADCR^(1<<ch_num);	//diselect channel number
	result=(ADDR>>6)&0x3FF;	//Extract result
	return result; //return result
}
