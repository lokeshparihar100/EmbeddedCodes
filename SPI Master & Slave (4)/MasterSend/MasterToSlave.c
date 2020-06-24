#include<avr/io.h>
#include<avr/lcd.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void master_ini()
{
	DDRB=(1<<PB4)|(1<<PB5)|(1<<PB7);
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR1);
}
void master_tx(char data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}
char master_rx()
{
	SPDR=0XFF;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void main()
{
	_delay_ms(2000);
	DDRD=0XFF;
	
	lcd_initialize();
	lcd_cmd(0x80);
	lcd_string("lokesh");

	master_ini();
	_delay_ms(10);
	
	PORTB=(1<<PB4);
	_delay_ms(1000);
	PORTB= PORTB&0B11101111;
	_delay_ms(10);
	
	master_tx(14);
	_delay_ms(100);

	PORTB=(1<<PB4);
}
