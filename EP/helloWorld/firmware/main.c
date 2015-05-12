/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 1<<4;  
   /* insert your hardware initialization here */
    for(;;){
        char i;
	for (i=0;i<10;i++){
		_delay_ms(30);
} 
	PORTD ^= 1<<4;
    }
    return 0;   /* never reached */
}
