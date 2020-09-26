CC=gcc                      # compilador c
CFLAGS=-c -Wall             # flags pasados al complilador
LDFLAGS=­                    # flags pasados al linker
OBJS=temps_array.o          # lista de todos los archivos objeto
SOURCES=$(OBJS:.o=.c)		# lista de todos los archivos fuente
HEADERS=*.h					# lista de todos los archivos header
EXE=temps					# nombre del ejecutable
ZIPFILE=temps.tar.gz		# nombre del archivo comprimido del proyecto

# regla para generar el ejecutable
$(EXE): $(OBJS)
	@echo "### Generando ejecutable"
	$(CC) $(OBJS) -o $@

# regla para generar los archivos objeto
%.o: %.c Makefile $(HEADERS)
	@echo "### Compilando" $<
	$(CC) $(CFLAGS) -o $@ $<

# regla para borrar el resultado de la compilacion anterior
clean:
	@echo "### Borrando todo..."
	rm -f ./*.o
	rm -f $(EXE)

# regla para hacer todo desde el comienzo (borrar todo, compilar y linkear)
all: clean $(EXE)

# regla para generar el archivo comprimido del proyecto
zip:
	tar -czvf $(ZIPFILE)  $(HEADERS) *.c Makefile

