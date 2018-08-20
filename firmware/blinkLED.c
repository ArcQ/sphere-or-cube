#include <avr/io.h>
#include <util.delay,h>

int main(void) {
    // -------- Init -------------
    
    // Data Direction Register B, the 1 enables output
    DDRB = 0b00000010;

    // -------- Event Loop -------
    while (1) {
        PORTB = 0b00000010;
        _delay_ms(1000);
        PORTB = 0b00000000;
        _delay_ms(1000);

        int i = 0;
        for (i=0; i<2; i++) {
            PORTB = 0b00000010;
            _delay_ms(100);
            PORTB = 0b00000000;
            _delay_ms(100);
        }
    }
}
