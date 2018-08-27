#include <avr/io.h>
#include <util/delay.h>

#define FORWARD 1
#define BACKWARD 2

void change_direction(int dir) {
    PORTD = dir;
}

int main(void) {
    // -------- Init -------------
    
    // Data Direction Register C, the 1 enables output
    DDRD = 0b00000011;


   // SET H-BRIDGE PWM INPUT AS A CONSTANT FOR NOW
   DDRB |= (1 << DDB1);
   // PB1 as output
   OCR1A = 0x01FF;
   // set PWM for 50% duty cycle at 10bit
   TCCR1A |= (1 << COM1A1);
   // set non-inverting mode
   TCCR1A |= (1 << WGM11) | (1 << WGM10);
   // set 10bit phase corrected PWM Mode
   TCCR1B |= (1 << CS11);
   // set prescaler to 8 and starts PWM

    // -------- Event Loop -------
    while (1) {
        change_direction(FORWARD);
        _delay_ms(2000);
        change_direction(BACKWARD);
        _delay_ms(2000);
        // PORTD =  0b00000010;
        // _delay_ms(5000);
        // PORTD =  0b00000001;
        // _delay_ms(5000);
    }
}
