#include<avr/io.h>
#include<avr/lcd.h>
#include<avr/uart.h>
#include<util/delay.h>

void main()
{
	int i;
	
	DDRC=0XFF;
	lcd_initialize();
	usart_initialize();
while(1)
{
	char lati[12],lon[12];
char	a=usart_receive();
	if(a=='$')
{	a=usart_receive();
	if(a=='G')
{	a=usart_receive();
	if(a=='P')
{	a=usart_receive();
	if(a=='G')
{	a=usart_receive();
	if(a=='G')
{	a=usart_receive();
	if(a=='A')
{	a=usart_receive();
	if(a==',')
{	a=usart_receive();
	while(a!=',')
{	a=usart_receive();
}
	int  k=0;
	while(a!='N')
{
	a=usart_receive();
	lati[k]=a;
	k++;
}
	lati[k]='\0';
	lcd_cmd(0x80);
	lcd_string(lati);
	a=usart_receive();
	if(a==',')
{	int	j=0;
	while(a!='E')
{
	a=usart_receive();
	lon[j]=a;
	j++;
}
	lon[j]='\0';
	lcd_cmd(0xc0);
	lcd_string(lon);
}}}}}}}}}
	


}
