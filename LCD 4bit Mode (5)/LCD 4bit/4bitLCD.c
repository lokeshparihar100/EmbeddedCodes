#include<avr/io.h>
#include<util/delay.h>


void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	
	 int i,a[6]={0x80,0x81,0x82,0x83,0x84,0x85};
	 int c[7]={0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6};
	 int b[6]={'L','O','K','E','S','H'};
	 int d[7]={'P','A','R','I','H','A','R'};
	DDRD=0XFF;

	lcd_initialize();
	for(i=0;i<8;i++)
	{
	lcd_cmd(a[i]);
	lcd_data(b[i]);
	lcd_cmd(c[i]);
	lcd_data(d[i]);
	}
	

}

void lcd_initialize()
{	
	
	lcd_cmd(0x02);
//	lcd_cmd(0x04);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x28);
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
