#include <LPC21xx.H>
#include "header.h"
#define RBS (C2GSR&1);
u32 flag=0;
extern CAN2 v1;
void CAN2_Rx_Handler(void)__irq
{
	v1.id=C2RID;
	v1.dlc=((C2RFS>>16)&0xF);
	v1.rtr=((C2RFS>>30)&1);
	if(v1.rtr==0)
	{
		v1.byteA=C2RDA;
		v1.byteB=C2RDB;
	}	
	C2CMR=(1<<2);
	flag=1;
	VICVectAddr=0;	
}
void config_vic_for_CAN2(void)
{
	VICIntSelect=0;
	VICVectCntl2=27|(1<<5);
	VICVectAddr2=(u32)CAN2_Rx_Handler;
	VICIntEnable|=(1<<27);
	C2IER=1;
}
