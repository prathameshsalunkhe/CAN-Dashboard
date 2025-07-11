typedef unsigned char u8;								  
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;
typedef signed short int s16;

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);
extern void lcd_atof(float f);
extern void lcd_tx_string(char *ptr);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_rx_string(s8 *ptr,s32 len);
extern void lcd_tx_string(char *ptr);
extern void uart0_atoi(u32 num);
extern void uart0_atof(float num);
extern void uart0_hexa(char ch);

extern u32 adc_read(u8 ch_num);
extern void adc_init(void);

extern void config_vic_for_eint0(void);
extern void config_eint0(void);

extern void config_vic_for_uart0(void);
extern void config_uart0_interrupt(void);

extern int my_cmp(char *p,char *q);
extern void str_rev(char *p);

extern void spi_init(void);
extern u16 mcp3204_read(u8 ch_num);
extern u8 spi(u8 data);

typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;
typedef signed short int s16;

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);
extern void lcd_atof(float f);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_rx_string(s8 *ptr,s32 len);
extern void lcd_tx_string(char *ptr);
extern void uart0_atoi(u32 num);
extern void uart0_atof(float num);
extern void uart0_hexa(char ch);

extern u32 adc_read(u8 ch_num);
extern void adc_init(void);

extern void config_vic_for_eint0(void);
extern void config_eint0(void);

extern void config_vic_for_uart0(void);
extern void config_uart0_interrupt(void);

extern int my_cmp(char *p,char *q);
extern void str_rev(char *p);

extern void spi0_init(void);
extern u16 mcp3204_read(u8 ch_num);
extern u8 spi(u8 data);

extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);
extern void i2c_init(void);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);

typedef struct CAN2_MSG
{
	u32 id;
	u32 byteA;
	u32 byteB;
	u8 dlc;
	u8 rtr;
}CAN2;

extern void can2_init(void);
extern void can2_tx(CAN2 v);
extern void config_vic_for_uart0(void);
extern void config_uart0_interrupt(void);

extern void config_vic_for_timer0(void);
extern void timer0_config(void);
extern void config_vic_for_timer1(void);
extern void timer1_config(void);		
