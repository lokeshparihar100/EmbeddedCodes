#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 8000000UL

void usart_initialize()
{
	UBRRH=0;
	UBRRL=12;
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
	DDRB=0XFF;

	usart_initialize();
	
	while(1)
	{	
 char a=usart_receive();
 

	if(a=='B')
	{
		PORTB=0B00000101;
		
	}
	else if(a=='R')
	{
		PORTB=0B00000110;
		
	}
	else if(a=='F')
	{
		PORTB=0B00001010;
		
	}
	else if(a=='L')
	{
		PORTB=0B00001001;
		
	}
	else if(a=='S')
	{
		PORTB=0X00;

	}
	}
}

