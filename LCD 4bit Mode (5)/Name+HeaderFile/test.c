#include<avr/io.h>
#include<util/delay.h>
#include<avr/lcd.h>

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


