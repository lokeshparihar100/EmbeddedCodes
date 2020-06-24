#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,a[8]={1,2,4,8};
	int b[8]={128,64,32,16};
	DDRC=0XFF;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			PORTC=a[i];
			_delay_ms(100);
			PORTC=0X00;
			_delay_ms(1);
			PORTC=b[i];
			_delay_ms(100);
			PORTC=0X00;
			_delay_ms(1);
		}
	}
}
