#include<lpc21xx.h>
#include "header.h"

void uart0_init(unsigned int baud)
{
	int a[]={15,60,30,15,15};
	unsigned int result=0,pclk=0;
	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	
	PINSEL0=PINSEL0|0x5;
	U0LCR=0X83;
	U0DLL=result&0xFF;
	U0DLM=(result>>8)&0XFF;
	U0LCR=0X03;
}

#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}
void uart0_tx_string(s8 *ptr)
{
	while(*ptr!=0)
	{
		U0THR=*ptr;
		while(THRE==0);
		ptr++;
		//delay_ms(200);
	}
}
void uart0_rx_string(s8 *ptr,s32 len)
{
	s32 i;
	for(i=0;i<len;i++)
	{
		while(RDR==0);
		ptr[i]=U0RBR;
		if(ptr[i]=='\r')
		break;
	}
	ptr[i]='\0';
}

void uart0_atoi(int num)
{
	int a[5],j;
	if(num>0)
	{
		for(j=0;num;j++)
		{
			a[j]=((num%10)+48);
			num=num/10;
		}
		for(j=j-1;j>=0;j--)
		{
			uart0_tx(a[j]);
		}
	}
}

void uart0_atof(float f)
{
	int i,k;
	i=f;
	uart0_atoi(i);
	uart0_tx('.');
	if(f<0)
	f=-f;
	k=(f-i)*1000000;
	uart0_atoi(k);  
}





