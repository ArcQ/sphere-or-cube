.PHONY: all build flash

MCU =
F_CPU = 
BAUD = 

all: build flash
test:
	avr-gcc -g -Os -Wall -mcall-prologues -mmcu=atmega328 -c -o blinkLED.o blinkLED.c
	avr-gcc -g -Os -Wall -mcall-prologues -mmcu=atmega328 blinkLED.o -o blinkLED.obj
	avr-objcopy -R .eeprom -O ihex blinkLED.obj blinkLED.hex
	avrdude -c avrispv2 -p m328p -P /dev/ttyACM0 -e -v -U flash:w:blinkLED.hex

build:
	avr-gcc -g -Os -Wall -mcall-prologues -mmcu=atmega328 -c -o main.o main.c
	avr-gcc -g -Os -Wall -mcall-prologues -mmcu=atmega328 main.o -o main.obj
	avr-objcopy -R .eeprom -O ihex main.obj main.hex

flash:
	avrdude -c avrispv2 -p m328p -P /dev/ttyACM0 -e -v -U flash:w:main.hex

clean:
	rm *.elf *.obj *.hex *.o
