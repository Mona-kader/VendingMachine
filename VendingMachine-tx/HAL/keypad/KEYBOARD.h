#ifndef KEYBOARD_h_
#define KEYBOARD_h_

#include <avr/io.h>
#ifndef F_CPU
# define F_CPU 16000000UL
#endif
#include <util/delay.h>

#define keyboardDDR 	DDRC
#define KeyboardPORT 	PORTC
#define keyboardPIN 	PINC

void keyboardIntiat();
uint8_t keyboardScan();




#endif
