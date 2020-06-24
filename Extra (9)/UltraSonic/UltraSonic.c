#include<avr/io.h>
#include<util/delay.h>
//#include<avr/lcd.h>
void lcd_num(unsigned int n)
{
	unsigned int i=0;
	while(n!=0)
	{
		i=n%10;
		lcd_data(48+i);
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
	_delay_ms(10);
	PORTD=PORTD-0X04;
	_delay_ms(10);
	

	PORTD=((cmd<<4)&0xF0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0X04;
	_delay_ms(10);
	
}

void lcd_data(char data)
{
	PORTD=(data&0xF0)|0x05;
	_delay_ms(10);
	PORTD=PORTD-0X04;
	_delay_ms(10);
	
	PORTD=((data<<4)&0xF0)|0x05;
	_delay_ms(10);	
	PORTD=PORTD-0X04;
	_delay_ms(10);
}


void main()
{	
	DDRB=0b00000001;    //Ultra Sonic
	DDRD=0XFF;
	lcd_initialize();
	lcd_cmd(0xc3);
	lcd_data('L');
	
	while(1)
	{	unsigned int count=0;
		PORTB=0b00000001;      // Triggering (send wave)
		_delay_us(10);
		PORTB=0X00;
		_delay_us(400);

		for(unsigned int i=0;i<=37000;i++)
		{
			if(PINB==0b00000010)          //ECO (receive wave)
			{	while(PINB==0b00000010)
			{	
				count++;
				
				}
		
			}
		}
		lcd_cmd(0x84);
		lcd_num(count/90);
	}
}
