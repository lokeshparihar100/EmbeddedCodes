#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRA=0X00;
	DDRC=0XFF;

	while(1)
	{
		if(PINA==0b00000011)
		{	
			PORTC=0b00000011;
			}
		else if(PINA==0b00000001)
		{
			PORTC=0b10000001;
			}
		else if(PINA==0b00000010)
		{
			PORTC=0b01000010;
			}
		
		else if(PINA==0b00000000)
		{
			PORTC=0b11000000;
			}
	}
}
