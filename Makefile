MCU=atmega328p
MCU2=m328p
F_CPU=16000000UL
PORT=/dev/ttyACM0

CC=avr-gcc
OBJCOPY=avr-objcopy

CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.

# Change this appropriately
TARGET=analog_avr
SRCS=analog_avr.c

all:
	@${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	@${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
	@echo "Binaries ready"

flash:
	@echo "Uploading binaries"
	avrdude -p ${MCU} -c arduino -U flash:w:${TARGET}.hex:i -F -P ${PORT}

clean:
	rm -f *.bin *.hex
mf: all flash