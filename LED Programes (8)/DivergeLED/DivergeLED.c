#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,a[5]={8,4,2,1},b[5]={16,32,64,128};
	DDRC=0XFF;
	while(1)
	{
	  for(i=0;i<5;i++)
	  {
		PORTC=a[i];
		_delay_ms(1000);
		PORTC=b[i];
		_delay_ms(1000);
		PORTC=0X00;
		_delay_ms(1);
	  }
	}
}
