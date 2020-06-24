#include<avr/io.h>
#include<util/delay.h>
#include<avr/lcd.h>
#define F_CPU 8000000UL

void usart_initialize()
{
	UBRRH=0;
	UBRRL=51;
	UCSRB=0X18;
	UCSRC=0X86;
}
void usart_send(char data)
{
	while((UCSRA&0x20)==0);
	UDR=data;
}
char usart_receive()
{
	while((UCSRA&0X80)==0);
	return UDR;
}
void main()
{
	
	DDRD=0X02;
	DDRA=0XFF;
	lcd_initialize();
	usart_initialize();
	lcd_cmd(0x85);
	lcd_data('L');
	while(1)
	{
char a=usart_receive();
	if(a=='h')
	{
			lcd_cmd(0xc5);
		lcd_data('O');
	}
	else 
	{
		lcd_cmd(0xc7);
		lcd_data('K');
	}
	}
}

