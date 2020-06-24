#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/lcd.h>
#include<avr/uart.h>
#include<stdio.h>
#include<util/delay.h>

int i;
char buff[20],value,value1,value2;
void send1()
{
	PORTC=0B10000000;
	_delay_ms(1000);
	usart_transmit(0xEF);usart_transmit(0x01);usart_transmit(0xFF);usart_transmit(0xFF);
	usart_transmit(0xFF);usart_transmit(0xFF);usart_transmit(0x01);usart_transmit(0x00);
	usart_transmit(0x03);usart_transmit(0x01);usart_transmit(0x00);usart_transmit(0x05);
}



void send2()
{	PORTC=0B00010000;
	usart_transmit(0xEF);usart_transmit(0x01);usart_transmit(0xFF);usart_transmit(0xFF);
	usart_transmit(0xFF);usart_transmit(0xFF);usart_transmit(0x01);usart_transmit(0x00);
	usart_transmit(0x04);usart_transmit(0x02);usart_transmit(0x01);usart_transmit(0x00);
	usart_transmit(0x08);
}

void send3()
{	PORTC=0B00000010;
	usart_transmit(0xEF);usart_transmit(0x01);usart_transmit(0xFF);usart_transmit(0xFF);
	usart_transmit(0xFF);usart_transmit(0xFF);usart_transmit(0x01);usart_transmit(0x00);
	usart_transmit(0x08);usart_transmit(0x1B);usart_transmit(0x01);usart_transmit(0x00);
	usart_transmit(0x00);usart_transmit(0x03);usart_transmit(0xE9);usart_transmit(0x01);
	usart_transmit(0x11);
}

void got_data()
{	PORTC=0B11000000;
	for(i=0;i<9;i++)
{
	value=usart_receive();
}
	PORTC=0B00110000;
	value1=usart_receive();
value=usart_receive();
	value2=usart_receive();
}

int main(void)
{
	DDRD=0X02;				// USART
	DDRB=0XFF;				// LCD
	DDRC=0XFF;				

	usart_initialize();
	_delay_ms(10);
	lcd_initialize();
	_delay_ms(10);

	lcd_cmd(0x8a);
	lcd_string("Lokesh");

	send1();
	PORTC=0B01000000;

	for(i=0;i<12;i++)
{
	value=usart_receive();
}
	PORTC=0B00100000;
	send2();
	PORTC=0B00001000;
	for(i=0;i<12;i++)
{
	value=usart_receive();
}
	PORTC=0B00000100;
	send3();
	PORTC=0B00000001;
	got_data();
	PORTC=0B00001100;

	lcd_cmd(0xc4);
	lcd_num(value1);

	lcd_cmd(0xc8);
	lcd_num(value2);

	
/*	sprintf(buff,"%d--%d",value1,value2);
	lcd_cmd(0x85);
	lcd_string(buff);
	_delay_ms(1000); */

}

