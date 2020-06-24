#include<avr/io.h>
#include<util/delay.h>
 
void lcd_initialize()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0C);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
}

void lcd_cmd(char cmd)
{
	PORTD=(cmd&0xF0)|0x04;
	_delay_ms(1);
	PORTD=PORTD-0X04;

	PORTD=((cmd<<4)&0xF0)|0x04;
	_delay_ms(1);
	PORTD=PORTD-0X04;
}

void lcd_data(char data)
{
	PORTD=(data&0xF0)|0x05;
	_delay_ms(1);
	PORTD=PORTD-0X04;

	PORTD=((data<<4)&0xF0)|0x05;
	_delay_ms(1);
	PORTD=PORTD-0X04;
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

void main()
{
	DDRD=0XFF;
	int i,a[17]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
	int b[17]={0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xcA,0xcB,0xcC,0xcD,0xcE,0xcF};
	lcd_initialize();
	while(1)
	{ 
	  for(i=0;i<16;i++)
	  {
		lcd_cmd(a[i]);
		lcd_string("LOKESH");
		_delay_ms(1);
		lcd_cmd(b[i]);
		lcd_string("PARIHAR");
		_delay_ms(100);
		
		lcd_cmd(0x10);
		lcd_cmd(0x01);
	  }
	}
}
