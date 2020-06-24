#include<avr/io.h>
#include<util/delay.h>

/*void lcd_num(unsigned int x)
{
	int a=0;
	while(x!=0)
	{
		a=x%10;
		lcd_data(48+a);
		x/=10;
	}
}*/

lcd_specialchar()
{
	lcd_cmd(0x40);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x18);
	lcd_data(0x1c);
	lcd_data(0x02);
	lcd_data(0x02);

	lcd_cmd(0x48);
	lcd_data(0x03);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x0c);
	lcd_data(0x13);
	lcd_data(0x12);
	lcd_data(0x10);
	lcd_data(0x10);

	lcd_cmd(0x50);
	lcd_data(0x1f);
	lcd_data(0x0a);
	lcd_data(0x0a);
	lcd_data(0x0a);
	lcd_data(0x1a);
	lcd_data(0x0a);
	lcd_data(0x0a);
	lcd_data(0x0a);

	lcd_cmd(0x58);
	lcd_data(0x0f);
	lcd_data(0x01);
	lcd_data(0x0d);
	lcd_data(0x13);
	lcd_data(0x11);
	lcd_data(0x13);
	lcd_data(0x0d);
	lcd_data(0x01);

	lcd_cmd(0x60);
	lcd_data(0x1e);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x0c);
	lcd_data(0x12);
	lcd_data(0x02);
	lcd_data(0x02);
	lcd_data(0x04);

	lcd_cmd(0x68);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x00);
	lcd_data(0x0c);
	lcd_data(0x0e);
	lcd_data(0x02);
	lcd_data(0x01);
	lcd_data(0x01);

	lcd_cmd(0x70);
	lcd_data(0x1f);
	lcd_data(0x18);
	lcd_data(0x1c);
	lcd_data(0x02);
	lcd_data(0x02);
	lcd_data(0x04);
	lcd_data(0x18);
	lcd_data(0x1c);


	
}
lcd_specialcha()
{
	lcd_cmd(0x70);
	lcd_data(0x1b);
	lcd_data(0x10);
	lcd_data(0x10);
	lcd_data(0x10);
	lcd_data(0x10);
	lcd_data(0x10);
	lcd_data(0x10);
	lcd_data(0x10);
}
	
void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	
	 int i,a[6]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
//	int c[7]={0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6};
	
	DDRD=0XFF;
	lcd_initialize();

//	for(i=0;i<15;i++)
//	{
	lcd_specialchar();
	lcd_cmd(0x86);
	lcd_data(0);
	lcd_specialchar();
	lcd_cmd(0xc5);
	lcd_data(1);
	lcd_specialchar();
	lcd_cmd(0xc6);
	lcd_data(2);
	
	lcd_specialchar();
	lcd_cmd(0xc7);
	lcd_data(3);
	lcd_specialchar();
	lcd_cmd(0xc8);
	lcd_data(4);
	lcd_specialchar();
	lcd_cmd(0x87);
	lcd_data(5);

	
	lcd_specialchar();
	lcd_cmd(0xc9);
	lcd_data(6);
	lcd_specialcha();
	lcd_cmd(0xca);
	lcd_data(4);
//	lcd_cmd(0x01);
//	}
	
}

void lcd_initialize()
{	
	
	lcd_cmd(0x02);
	lcd_cmd(0x04);
	lcd_cmd(0x0c);
//	lcd_cmd(0x06);
	lcd_cmd(0x28);
	lcd_cmd(0x01);

}
void lcd_cmd(char cmd)
{
	PORTD=(cmd&0XF0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0X04;
	

	PORTD=((cmd<<4)&0xF0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0X04;
	
}

void lcd_data(char data)
{
	PORTD=(data&0xF0)|0x05;
	_delay_ms(10);
	PORTD=PORTD-0X04;
	
	PORTD=((data<<4)&0xF0)|0x05;
	_delay_ms(10);	
	PORTD=PORTD-0X04;
}
