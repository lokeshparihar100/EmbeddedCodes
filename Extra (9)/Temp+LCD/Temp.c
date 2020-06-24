#include<avr/io.h>
#include<util/delay.h>

unsigned int adc_read(unsigned int read)
{
	ADMUX=0X40|read;
	ADCSRA=0XD7;
	while((ADCSRA&0X10)==0);
	return ADC;
}

void lcd_num(unsigned int n)
{
	int i=0;
	while(n!=0)
	{
		i=n%10;
		lcd_data(48+i);
		_delay_ms(1000);
		

		n/=10;
	}
}

void lcd_initialize()
{	
	
	lcd_cmd(0x02);
	lcd_cmd(0x0c);
	lcd_cmd(0x04);
	lcd_cmd(0x28);

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

void main()
{
	int a,b;
	DDRD=0XFF;
	DDRA=0X00;
	lcd_initialize();
	while(1)
	{
		a=adc_read(0);
		
		b=a/2;
		lcd_cmd(0x84);
		lcd_num(b);
		lcd_cmd(0x86);
		lcd_data('C');
	}
}


		
