#include<avr/io.h>
#include<util/delay.h>

int main()
{    
      int i, j ;
     DDRC=0xFF;
     while(1)
	 {
     for( i=0,j=128; i<=128&&j>=0;)
      {
         PORTC= i ;
         _delay_ms(100);
	//	 PORTC= j ;
    //     _delay_ms(100);

		 i=i*2; 
		 j=j/2;
       }}
  return 0;
}
