#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/lcd.h>
#include<util/delay.h>
#include<avr/interrupt.h>

unsigned int overflow=0;

void start_timer()
{
	TCCR0=(1<<CS01)|(1<<CS00);
	TIMSK=(1<<TOIE0);
	TCNT0=0;
}

ISR(TIMER0_OVF_vect)
{
	overflow++;
}

void main()
{
	int count=0;
	DDRC=0XFF;
	DDRB=0XFF;
	DDRA=0X00;

	sei();
	start_timer();
	lcd_initialize();
	_delay_ms(10);
	lcd_cmd(0xc0);
	lcd_data('o');
	_delay_ms(10);
	while(1)
	{
		if(PINA==0X01)
	{	count++;
		lcd_cmd(0x85);
			lcd_cmd(0x04);
			lcd_num(count);
		}
		if(overflow>=1471)
		{	
			
			PORTC=0XF0;
			count=0;
			lcd_cmd(0x85);
			lcd_cmd(0x04);
			lcd_num(count);
			
			overflow=0;
		}
	}
	
}




