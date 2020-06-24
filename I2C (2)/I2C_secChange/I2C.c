#include<avr/io.h>
#include<util/delay.h>
#include<avr/lcd.h>

void i2c_ini()
{
	TWBR=32;
	TWSR=0;
}

void i2c_start()
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR  & (1<<TWINT)));
	while((TWSR & (0XF8))!=0X08);
}

void i2c_stop()
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void i2c_tx(char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}

char i2c_rx()
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}

void main()
{
	DDRA=0XFF;
	DDRD=0XFF;
	lcd_initialize();
	_delay_ms(2);
	i2c_ini();
	_delay_ms(2);

	i2c_start();		// start for write
	_delay_ms(2);

	i2c_tx(0xd0);     //address of DS1307 with write
	_delay_ms(2);

	i2c_tx(0X00);     //write at 00
	_delay_ms(2);

	i2c_tx(0x17);     // write 15
	_delay_ms(2); 

	i2c_stop();		  // stop
	_delay_ms(2);

while(1)
{
	i2c_start();		// start for read
	_delay_ms(2);

	i2c_tx(0xd0);		// address of DS1307 with write
	_delay_ms(2);

	i2c_tx(0x00);		//read at 00
	_delay_ms(2);
	 
	 i2c_stop();		// stop when reach at location
	 _delay_ms(2);

	 i2c_start();		// start for read
	 _delay_ms(2);

	 i2c_tx(0xd1);      // address of DS1307 with read
	_delay_ms(2);

	char a=i2c_rx();	// receive and store 
	_delay_ms(2);

//	PORTA=a;			// show at PORTA
	lcd_cmd(0x86);
	lcd_cmd(0x04);
	lcd_num(a);
	_delay_ms(2);

	i2c_stop();			// stop read
	_delay_ms(2);

}
}
