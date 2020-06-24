#include<avr/io.h>
#include<util/delay.h>

void lcd_ini()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
}
void lcd_cmd(char cmd)
{
	PORTD=(cmd&0xf0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0x04;
	PORTD=((cmd<<4)&0xf0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0x04;
}
void lcd_data(char data)
{
	PORTD=(data&0xf0)|0x05;
	_delay_ms(10);
	PORTD=PORTD-0x04;
	PORTD=((data<<4)&0xf0)|0x05;
	_delay_ms(10);
	PORTD=PORTD-0x04;
}

void main()
{
	DDRD=0xFF;
	DDRC=0X0F;
	
	lcd_ini();
	while(1)
	{
		lcd_cmd(0x85);
PORTC=0b11111110;

	if(PINC==0b11101110)
	{  lcd_data('1');
	}
	 else if(PINC==0b11011110)
	{	lcd_data('4');
	}
	else if(PINC==0b10111110)
	{	lcd_data('7');
	}
	 else if(PINC==0b01111110)
	{	lcd_data('*');
	}


PORTC=0b11111101;

	if(PINC==0b11101101)
	{	lcd_data('2');
	}
	 else if(PINC==0b11011101)
	{	lcd_data('5');
	}
	else if(PINC==0b10111101)
	{	lcd_data('8');
	}
	 else if(PINC==0b01111101)
	{	lcd_data('0');
	}


PORTC=0b11111011;

	if(PINC==0b11101011)
	{	lcd_data('3');
	}
	 else if(PINC==0b11011011)
	{	lcd_data('6');
	}
	else if(PINC==0b10111011)
	{	lcd_data('9');
	}
	 else if(PINC==0b01111011)
	{	lcd_data('#');
	}
	
}
}

