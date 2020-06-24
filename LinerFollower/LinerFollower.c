#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRC=0XFF;
	DDRA=0X00;

	if(PINA==0b00000010)
	{
		PORTC=0b00000101;  //forward
		_delay_ms(20);
		PORTC=0X00;
		_delay_ms(30);
	}
	else if(PINA==0b00000001)
	{
		PORTC=0b00001001;  //Right Turn
		_delay_ms(20);
		PORTC=0X00;
		_delay_ms(30);
	}
	else if(PINA==0b00000110||PINA==0b00000011||PINA==0b00000100)
	{
		PORTC=0b00000110;  //Left Turn
		_delay_ms(20);
		PORTC=0X00;
		_delay_ms(30);
	}
	else if(PINA==0b00000101)
	{
		PORTC=0b00001001;  //Right Turn
		_delay_ms(20);
		PORTC=0X00;
		_delay_ms(30);
	}
}
