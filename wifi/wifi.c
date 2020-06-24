#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/lcd.h>
#include<util/delay.h>
#include<stdio.h>


void usart_initialize()
{
	UBRRH=0;
	UBRRL=51 ;
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

void usart_str(char *ser)             // String Function
{
	int i=0;
	while(ser[i]!='\0')
	{
	//	lcd_data(ser[i]);
		usart_send(ser[i]);
		i++;
	}
}

void main()
{	
	DDRD=0X02;		// USART
	DDRB=0XFF;		// LCD
	DDRC=0XFF;
 	char a,buff[20];

	lcd_initialize();
	_delay_ms(10);
	usart_initialize();
	_delay_ms(200);

	lcd_cmd(0xc8);
	lcd_string("Lokesh"); 	 		// Check LCD

	usart_str("AT+CWMODE=3\r\n");
	_delay_ms(100);
	
	usart_str("AT+CIPMUX=1\r\n");
	_delay_ms(100);

	usart_str("AT+CIPSERVER=1,80\r\n");
	_delay_ms(100);

	a=usart_receive();

	while(1)
	{
		while(a!=':')
		{
			a=usart_receive();
		}

		a=usart_receive();
		if(a=='1')
		{
			PORTC=0XFF;
			_delay_ms(1000);
		}
		
		sprintf(buff,"%c",a);
		lcd_cmd(0x85);
		lcd_string(buff);
		}
}

