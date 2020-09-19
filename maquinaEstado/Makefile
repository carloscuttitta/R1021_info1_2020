# ##############################
# Este es "un ejemplo" de como 
# construir un Makefile
# ##############################

# Mis configuraciones  
OBJS=maquinaEstados.o funciones.o	# lista de todos los archivos objeto
EXE=main				# nombre del ejecutable
ZIPFILE=MaquinaEstado.tar.gz		# nombre del archivo comprimido del proyecto

## Configuracion
CC=gcc					# compilador c
CFLAGS=-c -Wall				# flags pasados al complilador
LDFLAGS=­				# flags pasados al linker
SOURCES=$(OBJS:.o=.c)			# lista de todos los archivos fuente
HEADERS=*.h				# lista de todos los archivos header

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
	tar -czvf $(ZIPFILE) $(HEADERS) $(SOURCES) Makefile

