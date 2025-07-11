#include <LPC21xx.H>
#include"header.h"
u32 flag=0;
u8 temp;
void uart0_Handler(void)__irq
{
int r=U0IIR&0x0E;
if(r==4)
 {
 temp=U0RBR;
 U0THR=temp;
 flag=1;
 }
VICVectAddr=0;
}
void config_vic_for_uart0(void)
{
VICIntSelect=0;
VICVectCntl0=6|(1<<5);
VICVectAddr0=(u32)uart0_Handler;
VICIntEnable=(1<<6);
}
void config_uart0_interrupt(void)
{
U0IER=1;
}
