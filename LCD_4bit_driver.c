#include<lpc21xx.h>
#include"header.h"
void lcd_data(unsigned char data)
{
	unsigned int temp;
	IOCLR1=0XFE<<16;
	temp=(data&0xf0)<<16;
	IOSET1=temp;
	
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	
	IOCLR1=0XFE<<16;
	temp=(data&0x0f)<<20;
	IOSET1=temp;
	
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}

void lcd_cmd(unsigned char cmd)
{
	unsigned int temp;
	IOCLR1=0xFE<<16;
	temp=(cmd&0xf0)<<16;
	IOSET1=temp;
	
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	
	
	IOCLR1=0xFE<<16;
	temp=(cmd&0x0F)<<20;
	IOSET1=temp;
	
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}
void lcd_init()
{
IODIR1=0XFE<<16;
PINSEL2=0X0;
IOCLR1=1<<19;
lcd_cmd(0x02);
 lcd_cmd(0x28);
 lcd_cmd(0x0E);
lcd_cmd(0x01);

} 
void lcd_string(char *ptr)
{
	while(*ptr!='\0')
	{
	lcd_data(*ptr);
		ptr++;
	}
}
void lcd_atof(float f)
{
	int i;
	i=f;
	lcd_atof(i);
	lcd_data('.');
	if(f<0)
	f=-f;
	i=(f-i)*1000000;
	lcd_atof(i);
}
void lcd_cgram1(void)  //CGRAM
{
	u8 j;
	u8 b[8]={0x00,0x04,0x02,0x1f,0x1f,0x02,0x04,0x00};
	lcd_cmd(0x40);
	for(j=0;j<8;j++)
	{
		lcd_data(b[j]);
	}
}
void lcd_cgram2(void)  //CGRAM
{
	u8 k;
	u8 c[8]={0x00,0x04,0x08,0x1f,0x1f,0x08,0x04,0x00};
	lcd_cmd(0x48);
	for(k=0;k<8;k++)
	{
		lcd_data(c[k]);
	}
}
void lcd_cgram3(void)  //CGRAM
{
	u8 l;
	u8 d[8]={0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x00};
	lcd_cmd(0x50);
	for(l=0;l<8;l++)
	{
		lcd_data(d[l]);
	}
}

