CC=gcc
CFLAGS=-Wall -c
LDFLAGS=-lm
OBJS=main.o sensores.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h
ZIPFILE=sensores.tar.gz

sens: $(OBJS)
	@echo "### Generando ejecutable"
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c Makefile $(HEADERS)
	@echo "### Compilando" $<
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo "### Borrando todo..."
	rm -f ./*.o
	rm -f sens

all: clean sens

zip:
	tar -czvf $(ZIPFILE)  $(HEADERS) *.c Makefile
