CC=gcc
CFLAGS=-c
LDFLAGS=­
OBJS=sensores.o main_original.o main_control_c.o main_multiple.o main_alarma.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

sens: $(OBJS)
	$(CC) main_original.o sensores.o -o sens_original 
	$(CC) main_control_c.o sensores.o -o main_control_c 
	$(CC) main_multiple.o sensores.o -o sens_multiple 
	$(CC) main_alarma.o sensores.o -o sens_alarma 

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f sens_original
	rm -f main_control_c
	rm -f sens_multiple
	rm -f sens_alarma

all: clean sens

