#include<avr/io.h>
#include<util/delay.h>

void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	int i,j,a[17]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8b,0x8c,0x8d,0x8e,0x8f};
	char b[2]={'A','B'};
	int c[17]={0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
	DDRC=0XFF;
	DDRD=0XFF;

	lcd_initialize();
		
		
			while(1)
			{
			for(i=0;i<16;i++)
			{
			  for(j=0;j<2;j++)
			  {
				lcd_cmd(a[i]);
				lcd_cmd(a[i+1]);
				lcd_data(b[j]);
				_delay_ms(100);
				
				lcd_data(b[j+1]);
				_delay_ms(100);

				lcd_cmd(c[i]);
				lcd_cmd(c[i+1]);

			  }
			}}
		/*	for(j=0;j<8;j++)
			{	
				
				lcd_cmd(c[j]);
			}
	*/
			

}

void lcd_initialize()
{
	lcd_cmd(0x02);
//	lcd_cmd(0x04);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x28);
	
}
void lcd_cmd(char cmd)
{
	PORTD=(cmd&0xF0)|0x04;
	_delay_ms(1);
	PORTD-=0X04;

	PORTD=((cmd<<4)&0xF0)|0x04;
	_delay_ms(1);
	PORTD=PORTD-0X04;
}

void lcd_data(char data)
{
	PORTD=(data&0xF0)|0x05;
	_delay_ms(1);
	PORTD-=0X04;

	PORTD=((data<<4)&0xF0)|0x05;
	_delay_ms(1);
	PORTD=PORTD-0X04;
}
