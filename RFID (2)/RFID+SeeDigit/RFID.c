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
	char a[13];
	int i;
	DDRC=0XFF;

	lcd_initialize();
	usart_initialize();
	lcd_cmd(0xc5);
	lcd_data('L');
	while(1)
	{	for(i=0;i<12;i++)
	{
		
		a[i]=usart_receive();
	}
		lcd_cmd(0x80);
		lcd_string(a);
		

	}
}

