#include<avr/io.h>
#include<util/delay.h>
int sand(int);
void main()
{
	int i,k,m=8,p=7,b[9]={1,2,4,8,16,32,64,128};
	DDRC=0XFF;
		for(i=0;i<8;i++,p--)
		{
			sand(m);
			for(k=7;k>=p;k--)
			{
			PORTC=b[k];
			_delay_ms(100);
			}
			m-=1;
		}
}

int sand(int n)
{
	int j,a[9]={1,2,4,8,16,32,64,128}; 
	for(j=0;j<n;j++)
	  {
		PORTC=a[j];
		_delay_ms(50);
	  }	
}
