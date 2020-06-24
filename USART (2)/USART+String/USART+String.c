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
	char a[7],ser[7]={'L','O','K','E','S','H'};
	int c[7]={0x80,0x81,0x82,0x83,0x84,0x85,0x86};
	DDRD=0X02;
	DDRA=0XFF;
	lcd_initialize();
	usart_initialize();
	
	while(1)
	{
	for(int i=0;i<7;i++)
	{	
 	 a[i]=usart_receive();

	if(a[i]==ser[i])
	{
		lcd_cmd(c[i]);
		lcd_data(a[i]);
	}
	else 
	{
		lcd_cmd(0xc7);
		lcd_data('K');
	}
	}
	}
}

