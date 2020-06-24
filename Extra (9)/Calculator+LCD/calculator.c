#include<avr/io.h>
#include<util/delay.h>
#include<avr/lcd.h>

void lcd_initialize()
{
	lcd_cmd(0x02);
	lcd_cmd(0x0c);
	lcd_cmd(0x04);
	lcd_cmd(0x28);
	lcd_cmd(0x01);
}

void lcd_cmd(char cmd)
{
	PORTA=(cmd&0xf0)|0x04;
	_delay_ms(10);
	PORTA=PORTA-0X04;

	PORTA=((cmd<<4)&0xf0)|0x04;
	_delay_ms(10);
	PORTA=PORTA-0X04;
}

void lcd_data(char data)
{
	PORTA=(data&0xf0)|0x05;
	_delay_ms(10);
	PORTA=PORTA-0X04;

	PORTA=((data<<4)&0xf0)|0x05;
	_delay_ms(10);
	PORTA=PORTA-0X04;
}
void lcd_num(int x)
{
	int a=0;
	while(x!=0)
	{	a=x%10;
		lcd_data(48+a);
		x/=10;
	}
}

int keypad()
{ 	while(1){
PORTC==0B11111110;
	
	if(PINC==0B11101110)
	{
		while(PINC==0B11101110);
		return 'ON';
	}
	else if(PINC==0B11011110)
	{
		while(PINC==0B11011110);
		return 7;
	}
	else if(PINC==0B10111110)
	{
		while(PINC==0B10111110);
		return 8;
	}
	else if(PINC==0B01111110)
	{
		while(PINC==0B01111110);
		return 9;
	}
	else if(PIND==0B11111110)
	{
		while(PIND=0B11111110);
		return 'X';
	}
	else if(PIND==0B11111101)
	{
		while(PIND==0B11111101);
		return '/';
	}

PORTC=0B11111101;
	
	if(PINC==0B11101101)
	{
		while(PINC==0B11101101);
		return '+/-';
	}
	else if(PINC==0B11011101)
	{
		while(PINC==0B11011101);
		return 4;
	}
	else if(PINC==0B10111101)
	{
		while(PINC==0B10111101);
		return 5;
	}
	else if(PINC==0B01111101)
	{
		while(PINC==0B01111101);
		return 6;
	}
	else if(PIND==0B11111110)
	{
		while(PIND==0B11111110);
		return '-';
	}
	else if(PIND==0B11111101)
	{
		while(PIND==0B11111101);
		return 'M';
	}

PORTC=0B11111011;
	
	if(PINC==0B11101011)
	{
		while(PINC==0B11101011);
		return '%';
	}
	else if(PINC==0B11011011)
	{
		while(PINC==0B11011011);
		return 1;
	}
	else if(PINC==0B10111011)
	{
		while(PINC==0B10111011);
		return 2;
	}
	else if(PINC==0B01111011)
	{
		while(PINC==0B01111011);
		return 3;
	}
	else if(PIND==0B11111101)
	{
		while(PIND==0B11111101);
		return 'M-';
	}

/*PORTC=0B11110011;
	 if(PIND==0B11111110)
	{
		while(PIND==0B11111110);
		return '+';
	}*/

PORTC=0B11110111;
	
	if(PINC==0B11101011)
	{
		while(PINC==0B11101011);
		return '/';
	}
	else if(PINC==0B11011011)
	{
		while(PINC==0B11011011);
		return 0;
	}
	else if(PINC==0B10111011)
	{
		while(PINC==0B10111011);
		return '.';
	}
	else if(PINC==0B01111011)
	{
		while(PINC==0B01111011);
		return '=';
	}
	else if(PIND==0B11111101)
	{
		while(PIND==0B11111101);
		return 'M+';
	}
}}


void main()
{
	int i,b=0,sum=0;
	int j[16]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f};
	DDRA=0XFF;
	DDRC=0X0f;
	DDRD=0X00;
	PORTD=0XFF;
		lcd_initialize();
	for(i=0;i<16;i++)
	{
	int	a=keypad();
	lcd_cmd(j[i]);
	lcd_data(a);
if(a=='O')
	lcd_cmd(0x01);

else if(a>=0&&a<=9)
	{ 	 b=b*10+a;
	}
else if(a=='+')
	{	
		sum=sum+b;
		b=0;
	}
else if(a=='=')
	{
		lcd_data(0xc5);
		lcd_num(sum);
		break;
	}
	}
}

	


