#include <avr/io.h>
#include <util/delay.h>

#define __AVR_ATmega328P__ 1
#define FORWARD 1
#define BACKWARD 2

static inline void initADC0(void) {
    ADMUX |= (1 << REFS0); // Reference voltage on AVCC
    ADCSRA |= (1 << ADPS1) | (1 << ADPS0); // ADC clock prescaler /8
    ADCSRA |= (1 << ADEN); // Enable ADC
}
int main() {
    return sense_tap();
}

int sense_tap() {
    /* If the piezo sensor senses a vibration, light up the LED */

    // uint8_t led_value;
    // uint8_t i;
    uint16_t adc_value;

    initADC0();
    DDRB = (1 << DDB0);
    PORTB = 0;

    while (1) {
        ADCSRA |= (1 << ADSC);

        adc_value = ADC;
        if (adc_value < 512) {
            PORTB = (1 << PORTB0);
            // PORTB = 0;
        } else {
            // PORTB = (1 << PORTB0);
            PORTB = 0;
        }
    }
    return 0;
}

void change_direction(int dir) {
    PORTD = dir;
}

int run_wheel(void) {
    /* Run wheels at constant speed, switch direction every 2 seconds */
    
    // Data Direction Register D, the 1 enables output. 0 is input
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
