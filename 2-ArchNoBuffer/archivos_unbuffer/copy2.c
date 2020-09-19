#include <stdio.h>
#include <string.h>     // strcmp, strerror
#include <sys/types.h>  // open, fstat 
#include <sys/stat.h>   // open, fstat , struct stat
#include <fcntl.h>      // open
#include <errno.h>      // perror
#include <unistd.h>     // fstat, read, write, close 

#define TAMANIO_BLOQUE	1024

#define OK		0
#define EINVOCAR	1
#define ESONIGUALES	2
#define	EOPENORIG	3
#define	EOPENDEST	4	
#define EPROCORIG	5
#define ESTATORIG	6

int main(int argc, char **argv)
{
    int fdin, fdout;
    char buff[TAMANIO_BLOQUE];
    int leidos;
    struct stat st;

// verificacion de los parametros de la linea de comandos
    if(argc != 3)
    {
	printf("invocar %s <origen> <destino>\n", argv[0]);
	return EINVOCAR;
    }
    if(strcmp(argv[1], argv[2]) == 0)
    {
	printf("error <origen> y <destino> no pueden ser iguales\n");
	return ESONIGUALES;
    }	
	
// abro origen de los datos a copiar
    if((fdin = open(argv[1], O_RDONLY)) == -1)
    {
	printf("error al abrir el origen de los datos '%s'\n", argv[1]);
	perror(strerror(errno));
        return EOPENORIG;
    }
		
// leo los permisos del origen para hacer que el destino tenga los mismos
    if(fstat(fdin, &st) == -1)
    {
	printf("error al obtener los permisos del origen de los datos '%s'\n", argv[1]);
	perror(strerror(errno));
	close(fdin);
	return ESTATORIG;
    }

/*
 st_mode es 33188 en decimal o 0100644 en octal.
 El decimal no me dice nada, pero el octal significa algo, porque los últimos 9 bits (3 dígitos octales) son los permisos: 
 3 bits para el propietario
 3 bits para el grupo
 3 bits para el otro

 Owner: 6 that is rw- 
 Group: 4 that is r-- 
 Other: 4 that is r-- 

 el último 1 es esta constante y solo significa que es un archivo regular

 #define S_IFREG 0100000 
*/ 
    
    printf("st.st_mode '%o'\n", st.st_mode);
		
// abro destino de los datos a copiar
    if((fdout = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, st.st_mode)) == -1)
    {
	printf("error al abrir el destino de los datos '%s'\n", argv[2]);
	perror(strerror(errno));
	close(fdin);
	return EOPENDEST;
    }

// leo del origen y escribo en el destino
    do{
	if((leidos = read(fdin, buff, TAMANIO_BLOQUE)) == -1)
        {
            printf("error al procesar el origen de los datos '%s'\n", argv[1]);
            perror(strerror(errno));
            close(fdin);
            close(fdout);
            return EPROCORIG;
        }
	printf("leidos: %d\n", leidos);
	write(fdout, buff, leidos);
    }while(leidos == TAMANIO_BLOQUE);
	 	
    close(fdin);
    close(fdout);
    return OK;
}




/*
struct stat {
    mode_t		st_mode;
    ino_t		st_ino;
    dev_t		st_dev;
    dev_t		st_rdev;
    nlink_t		st_nlink;
    uid_t		st_uid;
    gid_t		st_gid;
    off_t		st_size;
    struct timespec	st_atim;
    struct timespec	st_mtim;
    struct timespec     st_ctim;
    blksize_t		st_blksize;
    blkcnt_t		st_blocks;
};

The struct stat structure includes at least the following members:

    st_dev – identifier of device containing file
    st_ino – inode number
    st_mode – protection mode; see also Unix permissions
    st_nlink – reference count of hard links
    st_uid – user identifier of owner
    st_gid – group identifier of owner
    st_rdev – device identifier (if special file)
    st_size – total file size, in bytes
    st_atime – time of last access
    st_mtime – time of last modification
    st_ctime – time of last status change
    st_blksize – preferred block size for file system I/O, which can depend upon both the system and the type of file system[3]
    st_blocks – number of blocks allocated in multiples of DEV_BSIZE (usually 512 bytes).

    ++++++++++++++++++++++---------------------------------+++++++++++++++++++++++++++++
    
    O_CREAT     Si el fichero no existe, será creado.
    
    O_TRUNC     Si el fichero ya existe y es un fichero regular  y  el  modo  de  apertura  permite
                escribir (por ejemplo es O_RDWR o O_WRONLY) será truncado a longitud 0.  Si el fichero es
                una FIFO o un fichero de dispositivo de terminal, la opción O_TRUNC es ignorada. En
                otro  caso  el efecto de O_TRUNC es indefinido.  (En muchas versiones de Linux será
                ignorado; en otras devolverá un error.)
    
    O_APPEND    El fichero se abrirá en modo de sólo-añadir. Antes de cada escritura, el  apuntador
                del fichero es posicionado al final del fichero, como se haría con lseek.
    
    ++++++++++++++++++++++++---------------------------------++++++++++++++++++++++++++++
    
     
    */
