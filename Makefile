CC = gcc
CFLAGS = -I./include -O2 -Wall
LIBS = -lopenblas -lm

#Build
all:
	$(CC) $(CFLAGS) src/QuantumRadar.c -o app $(LIBS)

#Clean
clean:
	rm -f app