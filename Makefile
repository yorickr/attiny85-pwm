
all:
	avr-gcc -Wall -Os -Wextra -DF_CPU=8000000 -mmcu=attiny85 -o main.o main.c
	avr-objcopy -j .text -j .data -O ihex main.o main.hex
	avrdude -c arduino -P/dev/ttyUSB0 -p attiny85 -b 19200 -U flash:w:main.hex:i

clean: /dev/null
	rm -f main.o main.hex
