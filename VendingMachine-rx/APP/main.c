

#ifndef F_CPU
# define F_CPU 8000000UL
#endif

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "../HAL/LCD/LCD.h"
#include "../MCAL/UART/uart.h"
#include "../LIB/string/STRING.h"
#include "../MCAL/timer/timer.h"

#define DRINK_CONTROLLER_PIN_COF				3
#define DRINK_CONTROLLER_DIR_COF				DDRB
#define DRINK_CONTROLLER_OUT_COF				PORTB

#define DRING_CONTROLLER_STOP_COF() 			DRINK_CONTROLLER_OUT_COF&=~(1<<DRINK_CONTROLLER_PIN_COF);\
												BUZZER_START();\
												_delay_ms(600);\
												BUZZER_STOP()

#define DRING_CONTROLLER_START_COF()			(DRINK_CONTROLLER_OUT_COF|=(1<<DRINK_CONTROLLER_PIN_COF))



//
#define DRINK_CONTROLLER_PIN_MOC				4
#define DRINK_CONTROLLER_DIR_MOC				DDRB
#define DRINK_CONTROLLER_OUT_MOC				PORTB

#define DRING_CONTROLLER_STOP_MOC() 			DRINK_CONTROLLER_OUT_MOC&=~(1<<DRINK_CONTROLLER_PIN_MOC);\
												BUZZER_START();\
												_delay_ms(600);\
												BUZZER_STOP()

#define DRING_CONTROLLER_START_MOC()			(DRINK_CONTROLLER_OUT_MOC|=(1<<DRINK_CONTROLLER_PIN_MOC))
//

#define DRINK_CONTROLLER_PIN_PPS				5
#define DRINK_CONTROLLER_DIR_PPS				DDRB
#define DRINK_CONTROLLER_OUT_PPS				PORTB

#define DRING_CONTROLLER_STOP_PPS() 			DRINK_CONTROLLER_OUT_PPS&=~(1<<DRINK_CONTROLLER_PIN_PPS);\
												BUZZER_START();\
												_delay_ms(600);\
												BUZZER_STOP()

#define DRING_CONTROLLER_START_PPS()			(DRINK_CONTROLLER_OUT_PPS|=(1<<DRINK_CONTROLLER_PIN_PPS))

//
#define DRINK_CONTROLLER_PIN_TEA				6
#define DRINK_CONTROLLER_DIR_TEA				DDRB
#define DRINK_CONTROLLER_OUT_TEA				PORTB

#define DRING_CONTROLLER_STOP_TEA() 			DRINK_CONTROLLER_OUT_TEA&=~(1<<DRINK_CONTROLLER_PIN_TEA);\
												BUZZER_START();\
												_delay_ms(600);\
												BUZZER_STOP()

#define DRING_CONTROLLER_START_TEA()			(DRINK_CONTROLLER_OUT_TEA|=(1<<DRINK_CONTROLLER_PIN_TEA))
//


#define DEBUG_STOP(string)   	  			LCDClearScreen();\
							  	  	  	  	LCDPrint(string);\
							  	  	  	  	while(1)

#define BUZZER_PIN							2
#define BUZZER_DIR 							DDRB
#define BUZZER_OUT							PORTB

#define  BUZZER_START()	 					(BUZZER_OUT|=(1<<BUZZER_PIN))
#define  BUZZER_STOP()	 					(BUZZER_OUT&=~(1<<BUZZER_PIN))

char read_drink();
void drinks_show(char drink,char count);
char wait_start_or_cancel();
void weclome_customer();
char read_drinkCount();




//RX
int main()
{



char drink,count;
uint8_t price;
LCDIntiat();
iniatUart(9600);
DRINK_CONTROLLER_DIR_COF|=1<<DRINK_CONTROLLER_PIN_COF;
DRINK_CONTROLLER_DIR_MOC|=1<<DRINK_CONTROLLER_PIN_MOC;
DRINK_CONTROLLER_DIR_PPS|=1<<DRINK_CONTROLLER_PIN_PPS;
DRINK_CONTROLLER_DIR_TEA|=1<<DRINK_CONTROLLER_PIN_TEA;

BUZZER_DIR|=1<<BUZZER_PIN;




while(1)
{


	drink=read_drink();
	count=read_drinkCount();

	if(wait_start_or_cancel() == '=' )
	{
		price= receiveChar();
		LCDClearScreen();
		LCDPrint("enter:");
		LCDRowColumn(1,11);
		LCDPrint("LE");
		do{
			LCDRowColumn(1,7);
			LCDPrint("   ");
			LCDRowColumn(1,7);
			LCDPrint( intToString(price) );
			price--;
		}while(receiveChar() =='c' );
		LCDClearScreen();
		drinks_show(drink,count);


	}
	else
	{
		//cancel
	}



}


return 0;
}


char read_drink()
{
	weclome_customer();
	return receiveChar();
}
char read_drinkCount()
{
	LCDClearScreen();
	LCDPrint("please enter");
	LCDRowColumn(2,1);
	LCDPrint("the count:");
	return receiveChar();
}

char wait_start_or_cancel()
{
	char ch;
	LCDClearScreen();
	LCDPrint("press:");
	LCDRowColumn(2,1);
	LCDPrint("1-cont 2-cancel");
	do{
		ch=receiveChar();
	}
	while( ch != '=' && ch != '<' );
	return ch;
}


void drinks_show(char drink,char count)
{
	
		LCDClearScreen();
		LCDPrint("drink:");
		LCDRowColumn(2,1);
		LCDSendChar(count);
		LCDSendChar('X');
		switch(drink)
		{
		case 'Z':
				LCDPrint("COF");
				DRING_CONTROLLER_START_COF();
				_delay_ms(3000);
				DRING_CONTROLLER_STOP_COF();
				break;
		case 'Y':
				LCDPrint("MOC");
				DRING_CONTROLLER_START_MOC();
				_delay_ms(3000);
				DRING_CONTROLLER_STOP_MOC();
				break;
		case 'X':
				LCDPrint("PPS");
				DRING_CONTROLLER_START_PPS();
				_delay_ms(3000);
				DRING_CONTROLLER_STOP_PPS();
				break;
		case 'W':
				LCDPrint("TEA");
				DRING_CONTROLLER_START_TEA();
				_delay_ms(3000);
				DRING_CONTROLLER_STOP_TEA();
				break;
	      }

}

inline void weclome_customer()
{
	LCDClearScreen();
	LCDPrint("Welcome please");
	LCDRowColumn(2,1);
	LCDPrint("enter drink ...");
	_delay_ms(2000);
	LCDClearScreen();
	LCDPrint("CAF 5LE MOC 4LE");
	LCDRowColumn(2,1);
	LCDPrint("PPS 3LE TEA 2LE");
}

