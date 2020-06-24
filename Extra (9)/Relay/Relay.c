#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRB=0xFF;
	DDRC=0XFF;
	
	PORTB=0x01;
	PORTC=0XFF;
	_delay_ms(1000);
	PORTC=0X00;
	PORTB=0;
		
}
