#include <LPC21xx.H>
#include "header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)
CAN2 v1;
u32 temp=0,result=0;
u32 speed=0;
u32 flag1=0,flag2=0,flag3=0;
float vout=0,t1=0;
float result1=0;
u32 temperature=0;
extern u32 timer1,timer0;
int main()
{
	can2_init();
	adc_init();
	uart0_init(9600);
	config_vic_for_timer0();
	timer0_config();
	config_vic_for_timer1();
	timer1_config();

	v1.id=0x500; //identifier
	v1.rtr=0;// Data Frame
	v1.dlc=8; // 7 bytes data
	v1.byteA=0;
	v1.byteB=0;

	while(1)
	{       
		result=adc_read(2);
        temperature=adc_read(1);
			  vout=(temperature*3.3)/1023;
			  t1=(vout-0.5)/0.01;

			uart0_tx_string("\r\nuart speed");
			uart0_atoi(result);
			uart0_tx_string("\r\n");
			uart0_tx_string("\r\nuart temp");
			uart0_atoi(t1);
		
		if(timer1==1)
		{
			timer1=0;
			v1.byteA=result;
            v1.byteB=temperature;
			can2_tx(v1);
//			uart0_tx_string("\r\nuart speed");
//			uart0_atoi(result);
//			uart0_tx_string("\r\n");
//			uart0_tx_string("\r\nuart temp");
//			uart0_atof(vout);
		}
        if(sw1==0)
		{
			while(sw1==0);
			{
				flag1^=1;
				if(flag1)
				{
					v1.byteA=0x05;
					can2_tx(v1);
					v1.byteA=0;
				}
				else
				{
					v1.byteA=0x06;
					can2_tx(v1);
				}
				v1.byteA=0;
			}
		}
		if(sw2==0)
		{
			while(sw2==0);
			{
				flag2^=1;
				if(flag2)
				{
					v1.byteA=0x07;
					can2_tx(v1);
					v1.byteA=0;
				}
				else
				{
					v1.byteA=0x08;
					can2_tx(v1);
				}
				v1.byteA=0;
			}
		}
		if(sw3==0)
		{
			while(sw3==0);
			{
				flag3^=1;
				if(flag3)
				{
					v1.byteA=0x09;
					can2_tx(v1);
					v1.byteA=0;
				}
				else
				{
					v1.byteA=0x10;
					can2_tx(v1);
				}
				v1.byteA=0;
			}
		}
	}
}

