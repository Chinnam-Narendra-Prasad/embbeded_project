/**
 * @file activity1.c
 * @author Ch.Narendra Prasad
 * @brief Activity1 of embedded project
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include<util/delay.h>

/**
 * @brief main function to operate on button sensor and heater sensor to turn on LED
 *
 * @return int
 */

int main(void)
{
/**
 * @brief Main code
 *
 */

    DDRB |=(1<<PB0);    //SET BIT PB0 TO 1
    DDRD &=(1<<PD0);   //CLEAR BIT OF PD0
    PORTD |=(1<<PD0);   //SET BIT PDO TO 1
    DDRD &=(1<<PD4);   //CLEAR BIT OF PD4
    PORTD |=(1<<PD4);    //SET BIT PD4 TO 1

    while(1){
        if(!(PIND&(1<<PD0))) //Checking if the input bit to 0th bit of pinD is made 0 from 1 by pressing led
            {
                if(!(PIND&(1<<PD4))) //Checking if the input bit to 4th bit of pinB is made 0 from 1 by pressing led
                {
                    PORTB |=(1<<PB0);  //make 0th bit of port B as 1, makes led glow
                    _delay_ms(200);
                }
                else
                {
                PORTB &=~(1<<PB0); // make led off
                _delay_ms(200);
                }
            }
        else
            {
            PORTB &=~(1<<PB0); // make led off
            _delay_ms(200);
            }
        }


    return 0;
}
