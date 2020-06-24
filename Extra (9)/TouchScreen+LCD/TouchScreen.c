#include<avr/io.h>
#include<util/delay.h>


void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
unsigned int adc_read(unsigned int read)
{
	ADMUX=0X40|read;
	ADCSRA=0XD7;
	while((ADCSRA&0X10)==0);
	return ADC;
}
void lcd_num(int x)
{
	int i=0;
	while(x!=0)
	{
		i=x%10;
		lcd_cmd(0x04);
		lcd_data(48+i);
		_delay_ms(100);
		x/=10;
}}

void main()
{
	 DDRC=0XFF;
	 DDRD=0XFF;
	lcd_initialize();

	while(1)
	{
		int a,b;
		DDRA=0b11110101;
		PORTA=0b11111100;
		a=adc_read(1);
		lcd_cmd(0x82);
		lcd_num(a);

		DDRA=0b11111010;
		PORTA=0b11111100;
		b=adc_read(0);
		lcd_cmd(0xc2);
		lcd_num(b);

if(a>=800&&a<=850&&b>500&&b<=550)  //forward
{PORTC=0b00000101;
_delay_ms(100);}
if(a>=450&&a<=500&&b>=200&&b<=230)   //right
{PORTC=0b00000110;
_delay_ms(100);}
if(a>=550&&a<=600&&b>=800&&b<=830)  //left
{PORTC=0b00001001;
_delay_ms(100);}
if(a>=200&&a<=250&&b>=500&&b<=550)
{PORTC=0b00001010;
_delay_ms(100);}		
}

}

void lcd_initialize()
{	
	
	lcd_cmd(0x02);
	
	lcd_cmd(0x0c);
//	lcd_cmd(0x06);
	lcd_cmd(0x28);
	lcd_cmd(0x04);
	lcd_cmd(0x01);

}
void lcd_cmd(char cmd)
{
	PORTD=(cmd&0XF0)|0x04;
	_delay_ms(100);
	PORTD=PORTD-0X04;
	

	PORTD=((cmd<<4)&0xF0)|0x04;
	_delay_ms(100);
	PORTD=PORTD-0X04;
	
}

void lcd_data(char data)
{
	PORTD=(data&0xF0)|0x05;
	_delay_ms(100);
	PORTD=PORTD-0X04;
	
	PORTD=((data<<4)&0xF0)|0x05;
	_delay_ms(100);	
	PORTD=PORTD-0X04;
}
