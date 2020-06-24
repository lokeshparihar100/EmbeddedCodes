#include<avr/io.h>
#include<avr/lcd.h>
#include<avr/uart.h>
#include<util/delay.h>

void lcd_str(char *ser)             // String Function
{
	int i=0;
	while(ser[i]!='\0')
	{
		lcd_data(ser[i]);
		usart_transmit(ser[i]);
		i++;
	}
}


int keypad()                         // Function for Keypad
{
	while(1)
	{
		
PORTC=0b11111110;

	if(PINC==0b11101110)
	{  while(PINC==0b11101110);
		return 1;
	}
	 else if(PINC==0b11011110)
	{	while(PINC==0b11011110);
		return 4;
	}
	else if(PINC==0b10111110)
	{	while(PINC==0b10111110);
		return 7;
	}
	 else if(PINC==0b01111110)
	{	while(PINC==0b01111110);
		return '*';
	}


PORTC=0b11111101;

	if(PINC==0b11101101)
	{	while(PINC==0b11101101);
		return 2;
	}
	 else if(PINC==0b11011101)
	{	while(PINC==0b11011101);
		return 5;
	}
	else if(PINC==0b10111101)
	{	while(PINC==0b10111101);
		return 8;
	}
	 else if(PINC==0b01111101)
	{	while(PINC==0b01111101);
		return 0;
	}


PORTC=0b11111011;

	if(PINC==0b11101011)
	{	while(PINC==0b11101011);
		return 3;
	}
	 else if(PINC==0b11011011)
	{	while(PINC==0b11011011);
		return 6;
	}
	else if(PINC==0b10111011)
	{	while(PINC==0b10111011);
		return 9;
	}
	 else if(PINC==0b01111011)
	{	while(PINC==0b01111011);
		return '#';
	}
	
}
	
}


void main()
{
	DDRC=0X0F;
	DDRD=0X02;
	DDRB=0XFF;
	lcd_initialize();
	usart_initialize();
	lcd_cmd(0x8a);
	lcd_string("Lokesh");

	while(1)
	{ char a;
		a=keypad();
		if(a==4)
		{
			lcd_cmd(0x80);
			lcd_str("atd 9667500093;");
			usart_transmit(0x0d);
		}
		if(a==5)
		{
			lcd_cmd(0x80);
			lcd_str("ath");
			usart_transmit(0x0d);
		}
}}
