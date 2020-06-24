#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,a[9]={1,2,4,8,16,32,64,128},b[9]={128,64,32,16,8,4,2,1};
	DDRC=0XFF;
	while(1)
	{
	  for(i=0;i<9;i++)
	  {
		PORTC=a[i];
		_delay_ms(100);
		PORTC=b[i];
		_delay_ms(100);
		PORTC=0X00;
		_delay_ms(1);
	  }
	}
}
