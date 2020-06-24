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
{	int i=0;
	char a[5],b[3]={'B','A','C','K'},f[4]={"FRONT"},l[3]={"LEFT"},s[3]={"STOP"},r[4]={"RIGHT"};

	DDRD=0X02;
	DDRB=0XFF;

	usart_initialize();
	
	while(1)
	{	for(int i=0;i<5;i++)
	{
 a[i]=usart_receive();
 }
	for(i=0; i<5;i++)
	{
	if(a[i]==b[i])
	{
		PORTB=0B00000101;
		
	}
	/*else if(a[i]==r[i])
	{
		PORTB=0B00000110;
		
	}
	else if(a[i]==f[i])
	{
		PORTB=0B00001010;
		
	}
	else if(a[i]==l[i])
	{
		PORTB=0B00001001;
		
	}
	else if(a[i]==s[i])
	{
		PORTB=0X00;

	}*/
	}}
}

