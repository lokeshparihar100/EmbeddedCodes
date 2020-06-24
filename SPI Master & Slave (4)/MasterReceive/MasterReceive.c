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

	DDRD=0XFF;
	
	lcd_initialize();
	lcd_cmd(0x80);
	lcd_string("lokesh");

	master_ini();
	_delay_ms(10);
	
	
	char a=master_rx();
	lcd_cmd(0xc7);
	lcd_num(a);


}
