/*  Author: Sidharth Ramkumar (sramk002@ucr.edu)
 *  Partner(s) Name: none
 *      Lab Section: 022
 *      Assignment: Lab #7  Exercise #3
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
        //ADEN: setting this bit enables analog-to-digital conversion
        //ADSC: setting this bit starts the first conversion.
        //ADATE: setting this bit enables auto-triggering. Since we are in Free         Running Mode, a new conversion will trigger whenever the previous conver        sion completes.
}

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    ADC_init();
    while (1) {
        unsigned short x = ADC;
        unsigned char tmpB = 0x00;
        // Value of ADC register is now stored in variable x 
        if (x >= 0x018F){
           tmpB = 0x01;
        }

        if (x < 0x018F){
           tmpB = 0x00;
        }

        PORTB = tmpB;

    }
    return 1;
}
