#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef F_CPU
# define F_CPU 8000000UL
#endif
#include <util/delay.h>
#include "../HAL/keypad/KEYBOARD.h"
#include "../MCAL/UART/uart.h"



#define IR_PIN		6
#define IR_DIR 		DDRD
#define IR_OUT		PORTD
#define IR_IN		PIND
#define IR_READ()	( (IR_IN & (1<<IR_PIN)) !=0 )




uint8_t read_send_drink();
uint8_t read_send_drinkCount();
void read_send_continueOrCancel(uint8_t price);
void detect_coin();


//TX

int main()
{

uint8_t price;
keyboardIntiat();
iniatUart(9600);
IR_DIR&=~(1<<IR_PIN);
IR_OUT|=(1<<IR_PIN);


while(1)
{

	_delay_ms(3000);
	price=read_send_drink();
	price*=read_send_drinkCount();
	read_send_continueOrCancel(price);
}


return 0;
}

uint8_t read_send_drink()
{
	char option;
	do{

		option=keyboardScan();
	}
	while(option !='W' && option !='X' && option !='Y' && option !='Z');

	sendChar(option);

	return (option - 'U');
}
uint8_t read_send_drinkCount()
{
	char count;
	do{

		count=keyboardScan();
	}
	while(count < '1'  ||  count >'9');

	sendChar(count);
	return (count - 0x30);
}
void read_send_continueOrCancel(uint8_t price)
{
	char option;
	do{

		option=keyboardScan();
	}
	while(option !='=' && option !='<');
	sendChar(option);
	if(option=='=')
	{
		sendChar( price ); 	//send  price


		while(price--)
		{
			detect_coin();
		}
		sendChar('e'); //end of coins count
	}


}

void detect_coin()
{
	uint8_t prev_state;
	static uint8_t  state=1;
	do
	{
		do
		{
		prev_state=state;
		state=IR_READ();
		}
		while(  (state==1) || (prev_state==0)   );
	_delay_ms(3);
	state=IR_READ();
	}
	while(  (state==1) || (prev_state==0) );


		sendChar('c');


}


