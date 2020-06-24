#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int i,j,k,l,p=10;
	int a[10]={64,121,36,48,25,18,2,120,0,16};
	DDRC=0XFF;
	DDRD=0XFF;
while(1)
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<p;j++)
		{
			for(k=0;k<6;k++)
			{
				for(l=0;l<10;l++)
				{
					PORTD=16;
					PORTC=a[l];
					_delay_ms(1);

					PORTD=8;
					PORTC=a[k];
					_delay_ms(10);

					PORTD=4;
					PORTC=a[j];
					_delay_ms(1);

					PORTD=2;
					PORTC=a[i];
					_delay_ms(10);

					if(i==2)
					p=4;
					else
					p=10;

}}}}}
}
