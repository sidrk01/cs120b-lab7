/*  Author: Sidharth Ramkumar (sramk002@ucr.edu)
 *  Partner(s) Name: none
 *      Lab Section: 022
 *      Assignment: Lab #7  Exercise #4
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 *
 *      Demo Video: https://youtu.be/ldOcv_y2CZY
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
   while (1){
    unsigned short x = ADC; // Value of ADC register is now stored in variable x 
    unsigned char tmpB = 0x00;
    
     if (x >= 0 && x <= 0x0063){
      tmpB = 0x01;
    } else if (x > 0x0063 && x <= 0x00C6){
      tmpB = 0x03;
    } else if (x > 0x00C6 && x <= 0x0129){
      tmpB = 0x07;
    } else if (x > 0x0129 && x <= 0x018C){
      tmpB = 0x0F;
    } else if (x > 0x018C && x <= 0x01EF){
      tmpB = 0x1F; 
    } else if (x > 0x01EF && x <= 0x0252){
      tmpB = 0x3F;
    } else if (x > 0x0252 && x <= 0x02B5){
      tmpB = 0x7F;
    } else {
      tmpB = 0xFF;
    }
    
    PORTB = tmpB;
    
  
   }
  return 1;  
}
