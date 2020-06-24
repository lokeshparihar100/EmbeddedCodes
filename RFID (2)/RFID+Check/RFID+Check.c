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
{  int i;
	char a[12];
		char c[12]={'1','8','0','0','8','9','2','3','B','2','0','0'};
		char d[12]={'0','D','0','0','7','6','C','C','A','8','1','F'};
	DDRC=0XFF;

	lcd_initialize();
	usart_initialize();
	lcd_cmd(0x80);
	lcd_string("Swipe your card");
	_delay_ms(10000);
	lcd_cmd(0x01);
	while(1)
	{	
		int count=0;
		int coun=0;

		for(i=0;i<12;i++)
	{
		a[i]=usart_receive();
	}
	
		for(i=0;i<12;i++)
		{if(a[i]==c[i])
			count++;	}

		for(i=0;i<12;i++)
			{if(a[i]==d[i])
			coun++;	}
	
	 if(count==12||coun==12)
	{
			lcd_cmd(0x82);
		lcd_string("Welcome");
		break;
		
	}
	else 
	{
		lcd_cmd(0x82);
		lcd_string("Try again");
		_delay_ms(100);
		lcd_cmd(0x01);
		
	}
	}
	}
	
	


