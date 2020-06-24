#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRD=0XFF;
	DDRA=0XF0;
	PORTD=0XFF;
	while(1)
	{



	if(PINA==0b00000001)
	{  
	PORTD=0b01111001;
	_delay_ms(1000);}
	 else if(PINA==0b00000100)
	{PORTD=0b00011001;
	_delay_ms(1000);}
	else if(PINA==0b00000111)
{	PORTD=0b01111000;
	_delay_ms(1000);}
	 else if(PINA==0b00001011)
{	PORTD=0b00110110;
	_delay_ms(1000);}


	

	else if(PINA==0b00000010)
{	PORTD=0b00100100;
	_delay_ms(1000);}
	 else if(PINA==0b00000101)
	{PORTD=0b00010010;
	_delay_ms(1000);}
	else if(PINA==0b00001000)
{	PORTD=0b00000000;
	_delay_ms(1000);}
	 else if(PINA==0b00001010)
{	PORTD=64;
	_delay_ms(1000);}




	else if(PINA==0b00000011)
{	PORTD=0b00110000;
	_delay_ms(1000);}
	 else if(PINA==0b00000110)
{	PORTD=0b00000010;
	_delay_ms(1000);}
	else if(PINA==0b00001001)
{	PORTD=0b00010000;
	_delay_ms(1000);}
	 else if(PINA==0b00001100)
{	PORTD=0b01001001;
	_delay_ms(1000);}
	
}
}

