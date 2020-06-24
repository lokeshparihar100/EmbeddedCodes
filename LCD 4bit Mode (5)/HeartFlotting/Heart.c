#include<avr/io.h>
#include<util/delay.h>


lcd_specialchar()
{
	lcd_cmd(0x40);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x0a);
	lcd_data(0x1f);
	lcd_data(0x1f);
	lcd_data(0x1f);
	lcd_data(0x0e);
	lcd_data(0x04);
}
	
	
void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	
	 int i,a[17]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
	
	DDRB=0XFF;
	lcd_initialize();
while(1)
{
	for(i=0;i<16;i++)
	{
	lcd_specialchar();
	lcd_cmd(a[i]);
	lcd_data(0);
	_delay_ms(100);
	lcd_cmd(0x01);
	}
}	
}

void lcd_initialize()
{	
	
	lcd_cmd(0x02);
	lcd_cmd(0x04);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x28);
	lcd_cmd(0x01);

}
void lcd_cmd(char cmd)
{
	PORTB=(cmd&0XF0)|0x04;
	_delay_ms(1);
	PORTB=PORTD-0X04;
	

	PORTB=((cmd<<4)&0xF0)|0x04;
	_delay_ms(1);
	PORTB=PORTD-0X04;
	
}

void lcd_data(char data)
{
	PORTB=(data&0xF0)|0x05;
	_delay_ms(10);
	PORTB=PORTD-0X04;
	
	PORTB=((data<<4)&0xF0)|0x05;
	_delay_ms(10);	
	PORTB=PORTD-0X04;
}
