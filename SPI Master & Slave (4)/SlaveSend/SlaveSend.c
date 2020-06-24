#include<avr/io.h>
#include<avr/lcd.h>
#include<avr/interrupt.h>
#include<util/delay.h>


void slave_ini()
{
	DDRB=(1<<PB6);
	SPCR=(1<<SPE)|(1<<SPR1);
}
void slave_tx(char data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}
char slave_rx()
{
	
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void main()
{
	
	DDRD=0XFF;
	lcd_initialize();
	_delay_ms(10);
	slave_ini();
	_delay_ms(10);

	lcd_cmd(0xc3);
	lcd_string("lokesh");
	
	PORTB=(1<<PB4);
	_delay_ms(1000);
	
	PORTB= PORTB&0B11101111;
	_delay_ms(10);
	
	
	
	slave_tx(5);
	_delay_ms(10);

	PORTB=(1<<PB4);
	_delay_ms(100);
}




   	

