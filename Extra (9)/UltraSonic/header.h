#include<avr/io.h>
#include<util/delay.h>
#define RS 0
#define RW 1
#define EN 2
void lcd_initialize()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0c);
	lcd_cmd(0x04);
	lcd_cmd(0x01);
}

void lcd_cmd(char cmd)
{
	PORTD= 	cmd&0xf0;
	PORTD&= ~(1<<RS);
	PORTD&= ~(1<<RW);
	PORTD|= (1<<EN);

	PORTD= 	cmd<<4;
	PORTD&= ~(1<<EN);
}

void lcd_data(char data)
{
	PORTD= 	data&0xf0;
	PORTD|= (1<<RS);
	PORTD&= ~(1<<RW);
	PORTD|= (1<<EN);

	PORTD= 	data<<4;
	PORTD&= ~(1<<EN);
}

void lcd_num(int x)
{
	int a=0;
	while(x!=0)
	{
		a=x%10;
		lcd_data(a);
		x/=10;
	}
}
void lcd_string(char *ser)
{
	int i=0;
	while(ser[i]!='\0')
	{
		lcd_data(ser[i]);
		i++;
	}
}

unsigned int adc_read(unsigned int read)
{
	ADMUX=(1<<REFS0)|read;
	ADCSRA=(1<<RDEN)|(1<<ADSC)|(1<<ADIF)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	while(ADCSRA&0X10)==0);
	return ADC;
}
	
