#include<avr/io.h>
#include<util/delay.h>
void main()
{
	while(1)
	{
	DDRC=0XFF;

	PORTC=0b00000101;
	_delay_ms(10000);

	PORTC=0b00001010;
	_delay_ms(10000);

	PORTC=0b00001001;
	_delay_ms(10000);

	PORTC=0b00000110;
	_delay_ms(10000);
}
}
