
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void master_ini()
{
	DDRB=(1<<PB4)|(1<<PB5)|(1<<PB7);
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR1);
}
void master_tx(char data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}
char master_rx()
{
	SPDR=0XFF;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void sd_talk(char cmd, long arg)
{	
	cmd=cmd|0x40;
	master_tx(cmd);
	master_tx(arg>>24);
	master_tx(arg>>16);
	master_tx(arg>>8);
	master_tx(arg);
	master_tx(0x95);
}

void main()
{
	DDRA=0XFF;
	int i;
	char a[20];
	master_ini();
	_delay_ms(10);
	sd_talk(0,0);
	_delay_ms(10);

	for( i=0;i<20;i++)
	{
		PORTB=(1<<PB4);
		_delay_ms(10);
		PORTB=0B11101111;
		_delay_ms(10);
	}

	sd_talk(0,0);
	while(1)
	{ 
	  for(i=0;i<20;i++)
	  {
		a[i]=master_rx();
		if(a[i-1]==0&&a[i]==1)
		goto jump;
	  }
	}
	jump:
	PORTA=0X02;
	sd_talk(1,0);
	while(1)
	{ 
	  for(i=0;i<20;i++)
	  {
		a[i]=master_rx();
		if(a[i-1]==0&&a[i]==1)
		goto P;
	  }
	}
	P:
	PORTA=0XF0;
}
	
		
		

		



