#include<avr/io.h>
#include<util/delay.h>


lcd_ser(char *ser)
{
	int i=0;
	while(ser[i]!='/0')
	{
		lcd_data(ser[i]);
		i++;
	}
}

void lcd_initialize();
void lcd_cmd(char cmd);
void lcd_data(char data);
void main()
{
	
	char ser[7]={"WELCOME"};
	DDRC=0XFF;
	DDRD=0XFF;

	lcd_initialize();

			lcd_cmd(0X84);
			lcd_ser(ser[7]);
			

}

void lcd_initialize()
{
	lcd_cmd(0x02);
	lcd_cmd(0x04);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x38);
}
void lcd_cmd(char cmd)
{
	PORTC=8;
	PORTD=cmd;
	_delay_ms(100);
	PORTC=0;
}

void lcd_data(char data)
{
	PORTC=10;
	PORTD=data;
	_delay_ms(10);
	PORTC=2;
}
