#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRC=0XFF;
	DDRA=0X00;
	
	
	while(1)
	{
	if(PINA==0B00011010)
	{
		PORTC=0B00011010;
	}
	else if(PINA==0B00011001)
	{
		PORTC=0B00011001;
	}
	else if(PINA==0B00010101)
	{
		PORTC=0B00010101;
	}
	else if(PINA==0B00010110)
	{
		PORTC=0B00010110;
	}
	}
}
