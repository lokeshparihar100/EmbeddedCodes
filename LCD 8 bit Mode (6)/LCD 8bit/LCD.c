#include<avr/io.h>
#include<util/delay.h>

void lcdcmd(char cmd);
void lcddata(char data);


void main()
{
	DDRC=0XFF;
	DDRD=0XFF;

	lcdcmd(0x02);
	lcdcmd(0x38);
	lcdcmd(0x06);
	lcdcmd(0x04);
	lcdcmd(0x0c);


	lcdcmd(0x80);
	lcddata(76);

	lcdcmd(0x81);
	lcddata(79);

	lcdcmd(0x82);
	lcddata(75);

	lcdcmd(0x83);
	lcddata(69);

	lcdcmd(0x84);
	lcddata('S');

	lcdcmd(0x85);
	lcddata('H');



}

void lcdcmd(char cmd)
{
	PORTD=cmd;
	PORTC=0b00001000;
	_delay_ms(100);

	PORTC=0X00;
}

void lcddata(char data)
{
	PORTD=data;
	PORTC=0b00001010;
	_delay_ms(10);
	PORTC=0b00000010;
}
