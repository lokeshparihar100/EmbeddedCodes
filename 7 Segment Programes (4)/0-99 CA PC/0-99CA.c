#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,j,a[10]={64,121,36,48,25,18,2,120,0,16};
	DDRC=0XFF;
	DDRD=0XFF;
	for(i=0;i<10;i++)
	{
	for(j=0;j<10;j++)
		{
			PORTD=2;
			PORTC=a[i];
			_delay_ms(100);
		
		
			PORTD=4;
			PORTC=a[j];
			_delay_ms(50);
		}	
	}
}
