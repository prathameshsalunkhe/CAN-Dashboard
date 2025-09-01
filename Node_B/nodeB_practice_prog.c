/*#include <LPC21xx.H>
#include "header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
u32 temp2,vout,temperature;
extern u32 flag; //CAN Flag
CAN2 v1;
extern unsigned int timer1;
extern unsigned int timer2;
u32 sflag1=0,sflag2=0; //indi. flags
main()
{
	can2_init();
	uart0_init(9600);
	lcd_init();
	lcd_cgram();

	lcd_cmd(0xc6);
	lcd_data(3);
	lcd_cmd(0x80);
	delay_ms(100);
	lcd_data(0);
	lcd_cmd(0x8F);
	lcd_data(1);
//	lcd_cmd(0x87);
//	lcd_data(2);
//	lcd_data('D');
	lcd_cmd(0x0C);

	IODIR0=LED1|LED2|LED3;
	IOSET0=LED1|LED2|LED3;

	config_vic_for_timer1();
	timer1_config();
	config_vic_for_CAN2();	

	while(1)
		{
			if(flag==1)
			{
				 flag=0;
			
			
//		temp2=((v1.byteA>>8)&(0xFF)); //pre....
        temp2=((v1.byteB)&(0xFF));
		vout=(3.3*temp2)/1023;
		temperature=((vout-0.5)/0.01);
	//	uart0_atoi(temperature);
		    
				lcd_cmd(0xc1);
				lcd_data((temperature/100)+48);	
			 	lcd_data(((temperature/10)%10)+48);
				lcd_data((temperature%10)+48);
			
				
//			if(((v1.byteA>>8)&(0x0000FF))>=100) // for temperature
//			    {
//
//				lcd_cmd(0xc1);
//				lcd_data(((v1.byteA>>16)&(0xFFFF)/100)+48);
//				lcd_data((((v1.byteA>>16)&(0xFFFF)/10)%10)+48);
//				lcd_data(((v1.byteA>>16)&(0xFFFF)%10)+48);
//				lcd_data('C');
//		    	}
//		    else
//			   {
//			   lcd_cmd(0xc2);
//			   lcd_data(((v1.byteA>>16)&(0xFFFF)/10)+48);
//			   lcd_data(((v1.byteA>>16)&(0xFFFF)%10)+48);
//			   lcd_data('C');
//			   }

/////////////////////////////////////////////////////////////////////
        	//for battery
		   if(((v1.byteB>>16)&(0xFF))==0)
		   {
		   lcd_cmd(0xc6);
		   lcd_data(3);
		   } 
		else if((((v1.byteB>>16)&(0xFF))>0) &&  (((v1.byteB>>16)&(0xFF))<=341)) 
			{
			  lcd_cmd(0xc6);
			  lcd_data(4);
			}
     	else if((((v1.byteB>>16)&(0xFF))>341) && (((v1.byteB>>16)&(0xFF))<=682))
			{
			lcd_cmd(0xc6);
			lcd_data(5);
			}
			else 	
			{
			lcd_cmd(0xc6);
			lcd_data(6);
			}
			
			 
///////////////////////////////////////////////////////////////////////////////////////
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
			//////////////////////////////////////////////////
			if((v1.byteA&0xFF)==0x07) //L ON
			{
				sflag1=1;
			}	
			if((v1.byteA&0xFF)==0x09)  //R ON
			{
				sflag2=1;
			}
			////////////////////////////////////////
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
			////////////////////////////////////////////////

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
  		}
	}
} */
		

 		//	lcd_cmd(0xc6);
//			lcd_data(((((v1.byteA>>8)&(0xFF))/10)+48));
//			lcd_data(((((v1.byteA>>8)&(0xFF))%10)+48));	  

/*switch(v1.byteA&0xFF)
  {
  case 0x05:IOCLR0=LED1;
  lcd_cmd(0x87);
  lcd_data(0);
  lcd_data('D');
  break;
  case 0x06:IOSET0=LED1;
  lcd_cmd(0x87);
  lcd_data(' ');
  lcd_cmd(0x88);
  lcd_data(' ');
  break;
  }*/