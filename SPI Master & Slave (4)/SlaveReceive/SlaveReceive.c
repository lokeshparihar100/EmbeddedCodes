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
	DDRC=0XFF;
	DDRD=0XFF;
	lcd_initialize();
	slave_ini();
	
	lcd_cmd(0xc3);
	lcd_string("lokesh");
	
	char a=slave_rx();
	
	lcd_cmd(0x85);
	lcd_cmd(0x04);
	lcd_num(a);
	
	PORTC=a;
	

}




   	

