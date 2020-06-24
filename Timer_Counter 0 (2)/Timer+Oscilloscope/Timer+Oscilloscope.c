#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/lcd.h>
#include<util/delay.h>
#include<avr/interrupt.h>


void PWM()
{
	TCCR0=(1<<WGM01)|(1<<COM01)|(1<<CS01)|(1<<CS00);  //(1<<WGM01)|
	TCNT0=0;
}

void main()
{
	DDRB=0X08;
	PWM();
	while(1)
	{
		OCR0=50;
		_delay_ms(1000);
		OCR0=100;
		_delay_ms(1000);
	}


	
	
}




