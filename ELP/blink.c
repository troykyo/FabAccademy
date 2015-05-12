//
// blink.c
//
// test blinking LED
//
// Troy @Troykyo
// 
//

#include <avr/io.h>
#include <util/delay.h>

#define output(directions,pin) (directions |= pin) // set port direction for output
#define set(port,pin) (port |= pin) // set port pin
#define clear(port,pin) (port &= (~pin)) // clear port pin
#define pin_test(pins,pin) (pins & pin) // test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set
#define led_delay() _delay_ms(50) // LED delay

#define led_port PORTA
#define led_direction DDRA
#define led_pin (1 << PA7)

int main(void) {
   //
   // main
   //
   // set clock divider to /1
   //
   CLKPR = (1 << CLKPCE);
   CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
   //
   // initialize LED pin
   //
   clear(led_port, led_pin);
   output(led_direction, led_pin);
   //
   // main loop
   //
   while (1) {
      set(led_port, led_pin);
      led_delay();
      clear(led_port, led_pin);
      _delay_ms(10);
      }
}
