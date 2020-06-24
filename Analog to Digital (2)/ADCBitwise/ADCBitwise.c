#include<avr/io.h>
#include<util/delay.h>


unsigned int adc_read(unsigned int read)
{
	ADMUX=(1<<REFS0)|read;
	ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADIF)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
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
	lcd_cmd(0x06);
	lcd_cmd(0x28);

}
void lcd_cmd(char cmd)
{
	PORTD=(cmd&0XF0)|0X04;
	_delay_ms(100);
	PORTD=PORTD-0X04;
	

	PORTD=((cmd<<4)&0xF0)|0X04;
	_delay_ms(100);
	PORTD=PORTD-0X04;
	
}

void lcd_data(char data)
{
	PORTD=(data&0xF0)|0X05;
	_delay_ms(100);
	PORTD=PORTD-0X04;
	
	PORTD=((data<<4)&0xF0)|0X05;
	_delay_ms(100);	
	PORTD=PORTD-0X04;
}

void main()
{
	int a;
	DDRD=0XFF;
	DDRA=0X00;
	lcd_initialize();
	while(1)
	{
		a=adc_read(0);
		lcd_cmd(0x84);
		lcd_num(a);
		if(a>=100&&a<200)
		PORTC=0X01;
		else if(a>=200&&a<400)
		PORTC=0X03;
		else if(a>=400&&a<600)
		PORTC=0X07;
		else if(a>=600&&a<800)
		PORTC=0X0F;
		else if(a>=800)
		PORTC=0X1F;

	}
}


		
