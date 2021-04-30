/*	Author: Sidharth Ramkumar (sramk002@ucr.edu)
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	//ADEN: setting this bit enables analog-to-digital conversion
	//ADSC: setting this bit starts the first conversion.
	//ADATE: setting this bit enables auto-triggering. Since we are in Free		Running Mode, a new conversion will trigger whenever the previous conver	sion completes.
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00; 
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    ADC_init();
    while (1) {
	unsigned short x = ADC;
	// Value of ADC register is now stored in variable x 
	unsigned char tmpB = (char)x;
	unsigned char tmpD = (char)(x >> 8);
	tmpD = (tmpD & 0x03);
	
	PORTB = tmpB;
	PORTD = tmpD;
    }
    return 1;
}
