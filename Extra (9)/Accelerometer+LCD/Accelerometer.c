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
	 DDRA=0X00;
	 DDRD=0XFF;
	lcd_initialize();

	while(1)
	{
		int a,b,c;
		a=adc_read(0);
		lcd_cmd(0x82);
		lcd_num(a);

		b=adc_read(1);
		lcd_cmd(0x86);
		lcd_num(b);
		
		c=adc_read(2);
		lcd_cmd(0xc5);
		lcd_num(c);		
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
