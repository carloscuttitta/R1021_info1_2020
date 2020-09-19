all:
	gcc -Wall -o main main.c -ldl

libs:
	#gcc -c -fPIC -o printb.o printb.c
	#	gcc -c -fPIC -o printn.o printn.c
	#	gcc -shared -Wl,libprinter.so.1 -o libprinter.so.1.0.0 printb.o printn.o -lc
	gcc -dynamiclib -o libprint.dylib -dy printb.c printn.c

clean:
	rm -f main *.o *.so.*
