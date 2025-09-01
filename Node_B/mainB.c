#include <LPC21xx.H>
#include "header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
u32 temp2,vout,temp,speed,t1;
float vout1,temp1;
extern u32 flag; //CAN Flag
CAN2 v1;
extern unsigned int timer1;
extern unsigned int timer2;
u32 sflag1=0,sflag2=0; //indi. flags
u32 lower=0;
int main()
{
	IODIR0=LED1|LED2|LED3;
	IOSET0=LED1|LED2|LED3;
	can2_init();
	uart0_init(9600);
	lcd_init();
	lcd_cgram();
	lcd_cmd(0x80);
	delay_ms(100);
	lcd_data(0);
	lcd_cmd(0x8F);
	lcd_data(1);
	lcd_cmd(0x0C);
	
	config_vic_for_timer1();
	timer1_config();
	config_vic_for_CAN2();

	while(1)
	{
		//if(flag==1)
		//{
			flag=0;
            temp1=((v1.byteB)&(0xFFFF));
			temp2=((v1.byteA)&(0xFFFF)); 
			vout1=(temp1*3.3)/1023;
			  t1=(vout1-0.5)/0.01;
			vout=(280*temp2)/1023;
      
			lcd_cmd(0xc0);
			lcd_string("S:");
			lcd_cmd(0xc2);
			lcd_data((((vout/100))+48));
			lcd_data(((((vout/10)%10))+48));
			lcd_data((((vout%10))+48));
		       lcd_cmd(0xc5);
			lcd_string("k/h");
            lcd_cmd(0xC9);
            lcd_string("T:");
            lcd_data((((t1/100))+48));
			lcd_data(((((t1/10)%10))+48));
			lcd_data((((t1%10))+48));
		    lcd_data(223);
            lcd_string("c");

					 	uart0_tx_string("\r\nk/h");
						uart0_atoi(vout);
						uart0_tx_string("\r\n temp");
						uart0_atof(t1);
            

			if((v1.byteA&0xFF)==0x05)
			{
				lcd_cmd(0x87);
				lcd_data(2);
				lcd_data('D');
				IOCLR0=LED1;
			}
			if((v1.byteA&0xFF)==0x06)
			{
				lcd_cmd(0x87);
				lcd_data(' ');
				lcd_data(' ');
				IOSET0=LED1;
			}
		
			if((v1.byteA&0xFF)==0x07) //L ON
			{
				sflag1=1;
			}
			if((v1.byteA&0xFF)==0x09)  //R ON
			{
				sflag2=1;
			}
		
			if(sflag1==1) //for L indi.
			{
				if(timer1==1)
				{
					lcd_cmd(0x80);
					lcd_data(0);
					IOCLR0=LED2;
				}
				else
				{
					lcd_cmd(0x80);
					lcd_data(' ');
					IOSET0=LED2;
				}
			}
			if(((v1.byteA&0xFF)==0x08) || ((v1.byteA&0xFF)==0x09))
			{
				sflag1=0;
				lcd_cmd(0x80);
				lcd_data(0);
				IOSET0=LED2;
				}
				
				if(sflag2==1)
				{
					if(timer2==1)
					{
					lcd_cmd(0x8F);
					lcd_data(1);
					IOCLR0=LED3;
					}
					else
					{
						lcd_cmd(0x8F);
						lcd_data(' ');
						IOSET0=LED3;
					}
			}
			if(((v1.byteA&0xFF)==0x07) || ((v1.byteA&0xFF)==0x10))
			{
				sflag2=0;
				lcd_cmd(0x8F);
				lcd_data(1);
				IOSET0=LED3;	
			}
	//	}
	}
}

