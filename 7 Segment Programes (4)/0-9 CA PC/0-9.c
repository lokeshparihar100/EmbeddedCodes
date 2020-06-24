#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,a[10]={64,121,36,48,25,18,2,120,0,16};
	DDRC=0XFF;
	for(i=0;i<10;i++)
	{
		PORTC=a[i];
		_delay_ms(1000);
	}
}
