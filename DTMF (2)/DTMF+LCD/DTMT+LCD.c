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
	DDRD=0XFF;
	DDRA=0XF0;
	PORTD=0XFF;
	lcd_ini();
	lcd_cmd(0x01);
	while(1)
	{



	if(PINA==0b00000001)
	{ 
		lcd_cmd(0x80);
		lcd_data('1'); 
	}
	 else if(PINA==0b00000100)
	{
		lcd_cmd(0x84);
		lcd_data('4');
	}
	else if(PINA==0b00000111)
	{
		lcd_cmd(0x87);
		lcd_data('7');
	}
	 else if(PINA==0b00001011)
	{
		lcd_cmd(0x8a);
		lcd_data('*');
	}


	

	else if(PINA==0b00000010)
	{	
		lcd_cmd(0x82);
		lcd_data('2');
	}
	 else if(PINA==0b00000101)
	{
		lcd_cmd(0x85);
		lcd_data('5');
	}
	else if(PINA==0b00001000)
	{
		lcd_cmd(0x88);
		lcd_data('8');
	}
	 else if(PINA==0b00001010)
	{
		lcd_cmd(0x80);
		lcd_data('0');
	}




	else if(PINA==0b00000011)
	{
		lcd_cmd(0x83);
		lcd_data('3');
	}
	 else if(PINA==0b00000110)
	{
		lcd_cmd(0x86);
		lcd_data('6');
	}
	else if(PINA==0b00001001)
	{
		lcd_cmd(0x89);
		lcd_data('9');
	}
	 else if(PINA==0b00001100)
	{
		lcd_cmd(0x8b);
		lcd_data('#');
	}
	
}
}

