               /* Program which work as ATM */
#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 8000000UL

void lcd_ini()                        // Initialize LCD
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
}
void lcd_cmd(char cmd)              // Send Instruction to instruction registor
{
	PORTD=(cmd&0xf0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0x04;
	PORTD=((cmd<<4)&0xf0)|0x04;
	_delay_ms(10);
	PORTD=PORTD-0x04;
}
void lcd_data(char data)             // Send data to data registor
{
	PORTD=(data&0xf0)|0x05;
	_delay_ms(10);
	PORTD=PORTD-0x04;
	PORTD=((data<<4)&0xf0)|0x05;
	_delay_ms(10);
	PORTD=PORTD-0x04;
}
void lcd_str(char *ser)             // String Function
{
	int i=0;
	while(ser[i]!='\0')
	{
		lcd_data(ser[i]);
		i++;
	}
}
int keypad()                         // Function for Keypad
{
	while(1)
	{
		
PORTC=0b11111110;

	if(PINC==0b11101110)
	{  while(PINC==0b11101110);
		return 1;
	}
	 else if(PINC==0b11011110)
	{	while(PINC==0b11011110);
		return 4;
	}
	else if(PINC==0b10111110)
	{	while(PINC==0b10111110);
		return 7;
	}
	 else if(PINC==0b01111110)
	{	while(PINC==0b01111110);
		return '*';
	}


PORTC=0b11111101;

	if(PINC==0b11101101)
	{	while(PINC==0b11101101);
		return 2;
	}
	 else if(PINC==0b11011101)
	{	while(PINC==0b11011101);
		return 5;
	}
	else if(PINC==0b10111101)
	{	while(PINC==0b10111101);
		return 8;
	}
	 else if(PINC==0b01111101)
	{	while(PINC==0b01111101);
		return 0;
	}


PORTC=0b11111011;

	if(PINC==0b11101011)
	{	while(PINC==0b11101011);
		return 3;
	}
	 else if(PINC==0b11011011)
	{	while(PINC==0b11011011);
		return 6;
	}
	else if(PINC==0b10111011)
	{	while(PINC==0b10111011);
		return 9;
	}
	 else if(PINC==0b01111011)
	{	while(PINC==0b01111011);
		return '#';
	}
	
}
	
}

void main()
{
	int a,b,c,d,p;
	DDRD=0xFF;
	DDRC=0X0F;
	
	lcd_ini();
	lcd_cmd(0x84);
	lcd_str("WELCOME");
	_delay_ms(1000);
	lcd_cmd(0x01);
	_delay_ms(1);

	lcd_cmd(0x82);
	lcd_str("Please Enter");
	lcd_cmd(0xc4);
	lcd_str("Your Pin");
	_delay_ms(2000);
	lcd_cmd(0x01);
	_delay_ms(1);

/*	jump:                                    // jump here when goto
		lcd_cmd(0x84);
		a=keypad();
		lcd_data('*');

		lcd_cmd(0x85);
		b=keypad();
		lcd_data('*');

		lcd_cmd(0x86);
		c=keypad();
		lcd_data('*');

		lcd_cmd(0x87);
		d=keypad();
		lcd_data('*');


		if(a==3&&b==4&&c==5&&d==6)              //Check password
		{
			lcd_cmd(0xc0);
			lcd_str("CORRECT PASSWORD");
			_delay_ms(1500);
			lcd_cmd(0x01);
			_delay_ms(1);

			lcd_cmd(0x80);
			lcd_str("1.WITHDRAW");
			lcd_cmd(0xc0);
			lcd_str("2.MINI STATEMENT");
			_delay_ms(1500);
			
			p=keypad();
			switch(p)                            //Swich Case
			{
				case 1:
					lcd_cmd(0x01);
					_delay_ms(1);
					lcd_cmd(0x81);
					lcd_str("ENTER AMOUNT");
					lcd_cmd(0xC4);
					a=keypad();
					lcd_data(48+a);
					lcd_cmd(0xC5);
					b=keypad();
					lcd_data(48+b);
					lcd_cmd(0xC6);
					c=keypad();
					lcd_data(48+c);
					_delay_ms(1500);
					lcd_cmd(0x01);
					_delay_ms(1);
					lcd_cmd(0x84);
					lcd_str("THANK YOU");
					break;
					
				case 2:
					lcd_cmd(0x01);
					_delay_ms(1);
					lcd_cmd(0x80);
					lcd_str("CURRENT BALANCE");
					lcd_cmd(0xC0);
					lcd_str("10,000 Rs.");
					_delay_ms(1500);
					lcd_cmd(0x01);
					_delay_ms(1);
					lcd_cmd(0x84);
					lcd_str("THANK YOU");
					break;
				default:
					lcd_cmd(0x01);
					_delay_ms(1);
					lcd_cmd(0x84);
					lcd_str("TIME OVER");
					_delay_ms(2000);
					lcd_cmd(0x01);
					_delay_ms(1);
					lcd_cmd(0x84);
					lcd_str("THANK YOU");
					break;

			}

		}
		else
		{
			lcd_cmd(0xc0);
			lcd_str("WRONG PASSWORD");
			_delay_ms(1500);
			lcd_cmd(0x01);
			_delay_ms(1);
			
			lcd_cmd(0x84);
			lcd_str("TRY AGAIN");
			_delay_ms(2000);
			lcd_cmd(0x01);
			_delay_ms(1);
			goto jump;                              //Jump statment
		}*/
}
                    /* Created by LP */
