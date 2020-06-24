#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,a[9]={1,2,4,8,16,32,64,128};
	DDRC=0XFF;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			PORTC=a[i];
			_delay_ms(100);
			PORTC=0X00;
			_delay_ms(100);
		}
		
		for(i=7;i>=0;i--)
		{
			PORTC=a[i];
			_delay_ms(100);
			PORTC=0X00;
			_delay_ms(100);
		}
	}
}
