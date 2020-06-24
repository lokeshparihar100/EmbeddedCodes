#include<avr/io.h>
#include<util/delay.h>

lcd_num(unsigned int x)
{
	int a=0;
	while(x!=0)
	{ 
		a=x%10;
		lcd_data(48+a);
		x=x/10;
	}
}

void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	
	
	DDRC=0XFF;
	DDRD=0XFF;

	lcd_initialize();

			lcd_cmd(0X84);
			lcd_num(487);
			

}

void lcd_initialize()
{
	lcd_cmd(0x02);
	lcd_cmd(0x04);
	lcd_cmd(0x0c);
	
	lcd_cmd(0x38);
}
void lcd_cmd(char cmd)
{
	PORTC=8;
	PORTD=cmd;
	_delay_ms(100);
	PORTC=0;
}

void lcd_data(char data)
{
	PORTC=10;
	PORTD=data;
	_delay_ms(10);
	PORTC=2;
}
