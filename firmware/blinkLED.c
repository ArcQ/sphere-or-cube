// #ifndef F_CPU
// #define F_CPU 20000000UL //20 Mhz Clock
// #endif 

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // -------- Init -------------
    
    // Data Direction Register B, the 1 enables output
    DDRB |= 1 << PINB1;

    // -------- Event Loop -------
    while (1) {
        PORTB |= 1 << PINB1;
        _delay_ms(1000);
        PORTB &= ~(1 << PINB1);
        _delay_ms(1000);

        int i = 0;
        for (i=0; i<2; i++) {
            PORTB |= 1 << PINB1;
            _delay_ms(100);
        PORTB &= ~(1 << PINB1);
            _delay_ms(100);
        }
    }
}
