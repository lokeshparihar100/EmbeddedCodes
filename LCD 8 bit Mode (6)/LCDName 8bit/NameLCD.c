#include<avr/io.h>
#include<util/delay.h>

void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	int i;
	int a[8]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87};
	int b[8]={'L','O','K','E','S','H'};
	DDRC=0XFF;
	DDRD=0XFF;

	lcd_initialize();
	for(i=0;i<7;i++)
	{
			lcd_cmd(a[i]);
			lcd_data(b[i]);
	}
}

void lcd_initialize()
{
	lcd_cmd(0x02);
	lcd_cmd(0x04);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
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
	_delay_ms(100);
	PORTC=2;
}
