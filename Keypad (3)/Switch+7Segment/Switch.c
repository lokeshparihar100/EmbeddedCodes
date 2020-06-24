#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRC=0XFF;
	DDRD=0X0F;
	PORTC=0XFF;
	while(1)
	{

PORTD=0b11111110;

	if(PIND==0b11101110)
	{  
	PORTC=0b01111001;
	_delay_ms(1000);}
	 else if(PIND==0b11011110)
	{PORTC=0b00011001;
	_delay_ms(1000);}
	else if(PIND==0b10111110)
{	PORTC=0b01111000;
	_delay_ms(1000);}
	 else if(PIND==0b01111110)
{	PORTC=0b00110110;
	_delay_ms(1000);}


	PORTD=0b11111101;

	if(PIND==0b11101101)
{	PORTC=0b00100100;
	_delay_ms(1000);}
	 else if(PIND==0b11011101)
	{PORTC=0b00010010;
	_delay_ms(1000);}
	else if(PIND==0b10111101)
{	PORTC=0b00000000;
	_delay_ms(1000);}
	 else if(PIND==0b01111101)
{	PORTC=64;
	_delay_ms(1000);}


PORTD=0b11111011;

	if(PIND==0b11101011)
{	PORTC=0b00110000;
	_delay_ms(1000);}
	 else if(PIND==0b11011011)
{	PORTC=0b00000010;
	_delay_ms(1000);}
	else if(PIND==0b10111011)
{	PORTC=0b00010000;
	_delay_ms(1000);}
	 else if(PIND==0b01111011)
{	PORTC=0b01001001;
	_delay_ms(1000);}
	
}
}

