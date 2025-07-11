typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short int u16;

extern void delay_ms(u32 ms);
extern void delay_sec(u32 sec);

extern void lcd_data(u8 data);
extern void lcd_init( void);
extern void lcd_cmd(u8 cmd);
extern void lcd_string(char *ptr);
void lcd_integer(int num);

extern void uart0_init(u32 baud);
extern void uart0_tx(u8 data);
extern u8 uart0_rx(void);
extern void uart0_tx_string(s8 *ptr);
extern void uart0_rx_string(s8 *ptr,s32 len);

extern void uart0_atof(float f);
extern void uart0_atoi(int num);
extern void uart0_hexa(char ch);
extern void uart0_integer(int n);
extern void uart0_float(float n);
extern void adc_init(void);

extern void adc_init(void);
extern u32 adc_read(u8 ch_num);

extern void config_eint0(void);
extern void config_vic_for_eint0(void);
extern void config_vic_for_uart0(void);
extern void config_uart0_interrupt(void);

extern int my_cmp(char *p,char *q);
extern int my_strcmp(s8 *s1,s8 *s2);

extern u16 mcp3204_read(u8 ch_num);
extern u8 spi0(u8 data);
extern void spi_init(void);

extern void i2c_init(void);
extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);

//////////CAN///////////////
typedef struct CAN2_MSG
{
u32 id;
u32 byteA;
u32 byteB;
u32 byteC; 
u8 dlc;
u8 rtr;	
}CAN2;

extern void can2_tx(CAN2 v);
extern void can2_init(void);

extern void config_vic_for_timer0(void);
extern void timer0_config(void);
extern void config_vic_for_timer1(void);
extern void timer1_config(void);
extern void config_vic_for_CAN2(void);
extern void lcd_cgram1(void);
extern void lcd_cgram2(void);
extern void lcd_cgram3(void);
extern void lcd_cgram(void); 




