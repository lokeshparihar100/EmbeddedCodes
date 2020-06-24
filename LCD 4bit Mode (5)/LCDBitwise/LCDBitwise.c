#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTB
#define RS 0
#define RW 1
#define EN 2



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
	lcd_cmd(0x01);

}
void lcd_cmd(char cmd)
{
	lcd=(cmd&0XF0);
	lcd &= ~(1<<RS);
	lcd &= ~(1<<RW);
	lcd |= (1<<EN); 

	_delay_ms(100);
	lcd &= ~(1<<EN);
	

	lcd=(cmd<<4);
	lcd &= ~(1<<RS);
	lcd &= ~(1<<RW);
	lcd |= (1<<EN);
	_delay_ms(100);
	lcd &= ~(1<<EN);
	
}

void lcd_data(char data)
{
	lcd=(data&0xF0);
	lcd |= (1<<RS);
	lcd &= ~(1<<RW);
	lcd |= (1<<EN);
	_delay_ms(100);
	lcd &= ~(1<<EN);
	
	lcd=(data<<4);
	lcd |= (1<<RS);
	lcd &= ~(1<<RW);
	lcd |= (1<<EN);
	_delay_ms(100);
	lcd &= ~(1<<EN);
}

void main()
{
	int a;
	DDRD=0XFF;
	DDRA=0X00;
	lcd_initialize();
	lcd_cmd(0x81);
	lcd_num(567);

	
}


		
