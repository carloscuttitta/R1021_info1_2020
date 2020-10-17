#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define TAM 1024

void sig_child(int signo)
{
    pid_t   pid;
    int     stat;
//waitpid - espera por el final de un proceso    
    while ( (pid = waitpid(-1,&stat,WNOHANG) ) > 0 )
    {
        printf("termino CHILD %d \n",pid);
    }
    return;
}

void interrumpir(int signum) {
  // Ctrl-C o kill -SIGINT [pid]
  // Static define una variable que mantiene su valor en múltiples invocaciones de la función.
  // Por más que lo inicialice con un valor, dicha inicializacion sucede una vez sola.
  static int count = 5;

  if (count > 0) {
    printf("Terminando en %d\n", count);
    count --;
  }
  else {
    // Termino "limpiamente" mi programa
    // Cierro archivos, conexiones, etc.
    exit(signum);
  }
}

void terminar(int signum) {
  // Termino mi programa
  // kill -SIGTERM [PID]
  printf("!!! Hachazo !!!\n");
  exit(signum);
}


int main(int ac, char *av[]){
    int res,nread;			// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket del cliente
    struct sockaddr_in my_addr;	        // mi direccion
    struct sockaddr_in cl_addr;	        // direccion del cliente
    unsigned int len;			// tamanio de la direccion
    char buf[TAM];			// buffer de recepcion
    pid_t   pid;

// verifica los argumentos de la linea de comandos
    if(ac !=2){
	printf("invocar %s <port_donde_servir>\n", av[0]);
	return -1;
    }
// crea un socket del tipo stream (TCP) en el dominio INET (internet)
    if ( (ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
    	perror(strerror(errno));
        return -1;
    }
// inicializa la direccion
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(av[1]));
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset((void *) &(my_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura

 //Avisar al sistema que se creo un socket
    if ( (res = bind( ssock, (struct sockaddr *)&my_addr, sizeof(my_addr) ) ) == -1){
    	perror(strerror(errno));
        return -1;
    }
// muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host
    printf(" sirviendo en %s:%d ...\n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));
// espera conexiones entrantes
    if ( listen(ssock, 5) == -1 ){
    	perror(strerror(errno));
        return -1;
    }
        
    signal (SIGCHLD, sig_child);    //dede llamar a waitpid()
    signal (SIGINT, interrumpir); 
    signal (SIGTERM, terminar); 

    printf("Proceso servidor pid: %d\n",getpid() );
    
    while(1){
// acepta la conexion entrante
        len = sizeof(my_addr);
        if ( (csock = accept(ssock, (struct sockaddr *)&cl_addr, &len)) == -1 ){
            perror(strerror(errno));
            return -1;
        }
        if ((pid = fork()) == 0) {
            printf("iniciando Proceso hijo pid: %d\n",getpid() );
            if (close(ssock) == -1) {
                perror(strerror(errno));
                exit(1); 
            }
            printf(" conectado desde %s:%d ...\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));

            while(1){
                if ((nread = read(csock, buf, TAM)) == 0){
                printf("saliendo del Proceso hijo pid: %d\n",getpid() );
                    break;
                }
                if ((write(csock, buf, nread)) < 0 ) {
                    perror(strerror(errno));
                    close(csock);
                    exit(1);
                }
            }
            if (close(csock) == -1) {  
                perror(strerror(errno));
                exit(1);
            }
            exit(0);
        } /* end fork */
        if (close(csock) == -1) {   // proceso padre
            perror(strerror(errno));
            exit(1);
        }
    } /* end while(1)*/
}

/*
La  función  wait  suspende  la  ejecución del proceso actual haste que un proceso hijo ha
terminado, o hasta que se produce una señal cuya acción es terminar el  proceso  actual  o
llamar  a  la  función  manejadora  de la señal. Si un hijo ha salido cuando se produce la
llamada (lo que se entiende por proceso "zombie"), la función vuelve inmediatamente. Todos
los recursos del sistema reservados por el hijo son liberados.

La  función  waitpid  suspende  la  ejecución  del  proceso  en  curso  hasta  que un hijo
especificado por el argumento pid ha terminado, o hasta que  se  produce  una  señal  cuya
acción es finalizar el proceso actual o llamar a la función manejadora de la señal.

Si  el  hijo  especificado  por  pid ha terminado cuando se produce la llamada (un proceso
"zombie"), la función vuelve inmediatamente. Todos los recursos del sistema reservados por
el hijo son liberados.

El valor de pid puede ser uno de los siguientes:

< -1    lo  que significa esperar a que cualquier proceso hijo cuyo ID del proceso es igual
        al valor absoluto de pid.
-1      lo que  significa  que  espera  por  cualquier  proceso  hijo;  este  es  el  mismo
        comportamiento que tiene wait.
0       lo  que  significa  que  espera  por cualquier proceso hijo cuyo ID es igual al del
        proceso llamante.
> 0    lo que significa que espera por el proceso hijo cuyo ID es igual al valor de pid.

El valor de options es un OR de cero o más de las siguientes constantes:

WNOHANG:    
    que significa que vuelve inmediatamente si ningún hijo ha terminado.
WUNTRACED:  
    que significa que también vuelve si hay hijos parados (pero no  rastreados),  y  de
    cuyo  estado  no ha recibido notificación.  El estado para los hijos rastreados que
    están parados también se proporciona sin esta opción.

(Para opciones exclusivas de Linux, vea más abajo.)
     
Si status no es NULL, wait o waitpid almacena la  información  de  estado  en  la  memoria
apuntada por status.

Si  el  estado puede ser evaluado con las siguientes macros (dichas macros toman el buffer
stat (un int) como argumento — ¡no un puntero al buffer!):

WIFEXITED(status)
    es distinto de cero si el hijo terminó normalmente.

WEXITSTATUS(status)
    evalúa los ocho bits menos significativos  del  código  de  retorno  del  hijo  que
    terminó,  que  podrían  estar activados como el argumento de una llamada a exit() o
    como el argumento de unñ return en el  programa  principal.  Esta  macro  solamente
    puede ser tenida en cuenta si WIFEXITED devuelve un valor distinto de cero.

WIFSIGNALED(status)
    devuelve true si el proceso hijo terminó a causa de una señal no capturada.

WTERMSIG(status)
    devuelve  el  número de la señal que provocó la muerte del proceso hijo. Esta macro
    sólo puede ser evaluada si WIFSIGNALED devolvió un valor distinto de cero.

WIFSTOPPED(status)
    devuelve true si el proceso hijo que provocó el  retorno  está  actualmente  pardo;
    esto  solamente  es posible si la llamada se hizo usando WUNTRACED o cuando el hijo
    está siendo rastreado (vea ptrace(2)).

WSTOPSIG(status)
    devuelve el número de la señal que provocó la parada del hijo. Esta macro solamente
    puede  ser  evaluada  si  WIFSTOPPED  devolvió  un valor distinto de cero.  Algunas
    versiones de Unix (p.e. Linux, Solaris, pero no AIX ni SunOS) definen  también  una
    macro  WCOREDUMP(status)  para  comprobar  si el proceso hijo provocó un volcado de
    memoria.  Utilícela solamente encerrada entre #ifdef WCOREDUMP ... #endif.              

VALOR DEVUELTO

    El ID del proceso del hijo que terminó, o cero  si  se  utilizó  WNOHANG  y  no  hay  hijo
    disponible, o -1 en caso de error (en este caso, errno se pone a un valor apropiado).



       
ERRORES

ECHILD  si  el  proceso  especificado  en pid no termina o no es hijo del proceso llamante.
        (Esto puede ocurrir para nuestros propios hijos si se asigna SIG_IGN como acción de
        SIGCHLD. Vea también la sección NOTAS DE LINUX sobre hilos.)

EINVAL  si el argumento options no fue valido.

EINTR   si no se activó WNOHANG y si no se ha capturado una señal no bloqueada o SIGCHLD.



OBSERVACIONES

    The  Single Unix Specification (Especificación para un Unix Único) describe un modificador
    SA_NOCLDWAIT (no soportado en Linux) tal que si este modificador está activo, o bien se ha
    asignado  SIG_IGN  como  acción  para  SIGCHLD,  entonces  los  hijos  que  terminan no se
    convierten en zombies y una llamada a wait() o waitpid() se bloqueará hasta que todos  los
    hijos hayan terminado y, a continuación, fallará asignando a errno el valor ECHILD.

    El  estándar POSIX original estableció como indefinido el comportamiento de tratar SIGCHLD
    con SIG_IGN.  Estándares posteriores, incluyendo SUSv2  y  POSIX  1003.1-2001  especifican
    este comportamiento describiéndolo tan solo como una opción conforme con XSI.  Linux no es
    conforme con el segundo de los dos puntos recién descritos:  si  se  hace  una  llamada  a
    wait()  o  waitpid() mientras SIGCHLD está siendo ignorada, la llamada se comporta como si
    SIGCHLD no estuviera siendo ignorada, es decir, se bloquea hasta  que  el  siguiente  hijo
    termina y luego devuelve el PID y el estado de ese hijo.

NOTAS DE LINUX

    En el núcleo de Linux, un hijo planificado por el núcleo no es una construcción distinta a
    un proceso. En su lugar, un hilo es simplemente un proceso que es creado usando la llamada
    al   sistema   única   en  Linux  clone(2)  ;  otras  rutinas  como  la  llamada  portable
    pthread_create(3) son implementadas usando clone(2).  Antes de la versión 2.4.  de  Linux,
    un  hilo era un caso especial de un proceso, y como consecuencia, un hilo no podía esperar
    al hijo de otro hilo, incluso cuando este último pertenecía al mismo grupo de hilos.   Sin
    embargo,  POSIX  recomienda  tal  funcionalidad,  y desde la versión 2.4. de Linux un hilo
    puede, y por defecto lo hará, esperar a hijos de otros hilos en el mismo grupo de hilos.

    Las siguientes opciones específicas de Linux codificadas en options se pueden utilizar con
    hijos creados usando clone(2).

__WCLONE
    Espera  por  hijos "clone" solamente. Si se omite espera sólo por hijos "no clone".
    (Un hijo "clone" es el que al terminar no  comunica  ninguna  señal,  o  una  señal
    distinta  de SIGCHLD a su padre.)  Esta opción es ignorada si se especifica también
__WALL.

__WALL 
    (Desde Linux 2.4) Espera por todos los hijos, sin importar su tipo ("clone"  o  "no
    clone").

__WNOTHREAD
    (Desde  Linux  2.4)  No espera por hijos de otros hilos en el mismo grupo de hilos.
    Era la opción por defecto antes de la versión 2.4. de Linux.


*/



/*
SEÑALES:
    signal - lista de las señales disponibles

DESCRIPCIÓN
    Linux  permite tanto las señales POSIX confiables (de aquí en adelante "señales estándar")
    como las señales POSIX en tiempo real.

Señales Estándar
    Linux soporta las señales estándar listadas a  continuación.  Muchos  números  de  señales
    dependen  de  la arquitectura, tal como se indica en la columna "Valor".  (Donde aparezcan
    tres valores, el primero de ellos es válido normalmente para alpha  y  sparc,  el  segundo
    para i386, ppc y sh, y el último para mips.  Un - indica que una señal no está presente en
    la arquitectura correspondiente.)

    Las entradas en la columna "Acción" de la tabla especifican la acción por defecto para  la
    señal de la siguiente manera:

Term   
    La acción por defecto es terminar el proceso.

Ign
    La acción por defecto es ignorar la señal.

Core
    La acción por defecto es terminar el proceso y realizar un volcado de memoria.

Stop
    La acción por defecto es detener el proceso.

En primer lugar se listan las señales descritas en el estándar POSIX.1 original.

       Señal      Valor     Acción   Comentario
       ──────────────────────────────────────────────────────────────────────
       SIGHUP        1       Term    Cuelgue detectado en la terminal de
                                     control o muerte del proceso de control
       SIGINT        2       Term    Interrupción procedente del teclado
       SIGQUIT       3       Core    Terminación procedente del teclado
       SIGILL        4       Core    Instrucción ilegal
       SIGABRT       6       Core    Señal de aborto procedente de abort(3)
       SIGFPE        8       Core    Excepción de coma flotante
       SIGKILL       9       Term    Señal de matar
       SIGSEGV      11       Core    Referencia inválida a memoria
       SIGPIPE      13       Term    Tubería rota: escritura sin lectores
       SIGALRM      14       Term    Señal de alarma de alarm(2)
       SIGTERM      15       Term    Señal de terminación
       SIGUSR1   30,10,16    Term    Señal definida por usuario 1
       SIGUSR2   31,12,17    Term    Señal definida por usuario 2
       SIGCHLD   20,17,18    Ign     Proceso hijo terminado o parado
       SIGCONT   19,18,25            Continuar si estaba parado
       SIGSTOP   17,19,23    Stop    Parar proceso
       SIGTSTP   18,20,24    Stop    Parada escrita en la tty
       SIGTTIN   21,21,26    Stop    E. de la tty para un proc. de fondo
       SIGTTOU   22,22,27    Stop    S. a la tty para un proc. de fondo

Las señales SIGKILL y SIGSTOP no pueden ser capturadas, bloqueadas o ignoradas.

A  continuación  se listan las señales que no aparecen en el estándar POSIX.1 pero que son
descritas en SUSv2 y SUSv3 / POSIX 1003.1-2001.

       Señal        Valor     Acción   Comentario
       ─────────────────────────────────────────────────────────────────────────
       SIGBUS      10,7,10     Core    Error de bus (acceso a memoria inválido)
       SIGPOLL                 Term    Evento que se puede consultar (Sys V).

                                       Sinónimo de SIGIO
       SIGPROF     27,27,29     A      Ha expirado el reloj de perfilado
                                       (profiling)
       SIGSYS      12,-,12      C      Argumento de rutina inválido (SVID)
       SIGTRAP        5        Core    Trampa de traza/punto de ruptura
       SIGURG      16,23,21     B      Condición urgente en conector (4.2 BSD)
       SIGVTALRM   26,26,28     A      Alarma virtual (4.2 BSD)
       SIGXCPU     24,24,30     C      Límite de tiempo de CPU excedido
                                       (4.2 BSD)
       SIGXFSZ     25,25,31     C      Límite de tamaño de fichero excedido
                                       (4.2 BSD)

En las versiones de Linux anteriores a  la  2.2  (incluida  ésta)  el  comportamiento  por
defecto para SIGSYS, SIGXCPU, SIGXFSZ, y (en otras arquitecturas distintas a SPARC y MIPS)
SIGBUS era terminar el proceso (sin realizar un volcado de memoria).  (En otros Unix's  la
acción  por  defecto para SIGXCPU y SIGXFSZ es terminar el proceso sin realizar un volcado
de memoria.)  Linux 2.4 cumple los requisitos del estándar POSIX 1003.1-2001 con  respecto
a estas señales, terminando el proceso con un volcado de memoria.

A continuación otras señales.

       Señal          Valor      Acción   Comentario
       ────────────────────────────────────────────────────────────────────────────────────
       SIGIOT           6         Core    Trampa IOT. Un sinónimo de SIGABRT
       SIGEMT      7,-,7  Term
       SIGSTKFLT     -,16,-       Term    Fallo de la pila en el coprocesador (no usada)
       SIGIO        23,29,22      Term    E/S permitida ya (4.2 BSD)
       SIGCLD        -,-,18       Ign     Un sinónimo de SIGCHLD
       SIGPWR       29,30,19      Term    Fallo de corriente eléctrica (System V)
       SIGINFO       29,-,-               Un sinónimo para SIGPWR
       SIGLOST        -,-,-       Term    Bloqueo de fichero perdido.
       SIGWINCH     28,28,20      Ign     Señal de reescalado de la ventana (4.3 BSD, Sun)
       SIGUNUSED     -,31,-       Term    Señal no usada.

(La señal 29 es SIGINFO / SIGPWR en la arquitectura alpha pero SIGLOST en sparc.)

La  señal  SIGEMT  no está especificada en el estándar POSIX 1003.1-2001, pero sin embargo
aparece en la mayoría de Unix's, donde su  comportamiento  por  defecto  es  habitualmente
terminar el proceso sin realizar un volcado de memoria.

La  señal  SIGPWR  (que no está especificada en el estándar POSIX 1003.1-2001) es ignorada
habitualmente por defecto en aquellos Unix's donde aparece.

La señal SIGIO (que no está especificada en el estándar POSIX 1003.1-2001) es ignorada por
defecto en muchos Unix's.

Señales en Tiempo real
    Linux  soporta  señales  en  tiempo  real  tal  como  está  definido  originalmente en las
    extensiones de tiempo real de POSIX.4  (ahora  incluidas  en  POSIX  1003.1-2001).   Linux
    soporta  32  señales  en  tiempo real, numeradas del 32 (SIGRTMIN) al 63 (SIGRTMAX).  (Los
    programas deben hacer referencia siempre a las señales en tiempo real usando  la  notación
    SIGRTMIN+n,  puesto que el rango de números de señales en tiempo real varía entre sistemas
    Unix's.)

    A diferencia de las señales estándar, las señales en tiempo real no tienen un  significado
    predefinido:  el  conjunto  al  completo  de  señales  en  tiempo  real  puede usarse para
    propósitos definidos por la aplicación.  (Observe,  sin  embargo,  que  la  implementación
    LinuxThreads usa las tres primeras señales en tiempo real.)

    La  acción  por  defecto  para una señal en tiempo real no manejada es terminar el proceso
    receptor.

Las señales en tiempo real se distinguen por lo siguiente:

1.  Varias instancias de señales en tiempo real pueden ser puestas en cola.  En contraste,
    si  varias  instancias  de  una  señal  estándar llegan mientras esa señal está siendo
    bloqueada, solamente la primera de ellas es puesta en cola.

2.  Si la señal se envía usando sigqueue(2), puede enviarse con la señal un valor (bien un
    entero  o  un puntero).  Si el proceso receptor establece un manejador para esta señal
    usando la bandera SA_SIGACTION en sigaction(2) puede obtener estos datos a través  del
    campo  si_value de la estructura siginfo_t pasada como segundo argumento al manejador.
    Además, los campos si_pid y si_uid de esta estructura pueden usarse  para  obtener  el
    identificador  de  proceso y el identificador de usuario real del proceso que envía la
    señal.

3.  Las señales en tiempo real se entregan en un orden  garantizado.   Varias  señales  en
    tiempo  real  del  mismo tipo llegan en el orden en que fueron enviadas.  Si se envían
    diferentes señales en tiempo real a un proceso, se comunican  comenzando  por  la  que
    tenga menor número.  (es decir, las señales con número bajo tienen mayor prioridad.)

Si hay señales estándar y en tiempo real pendientes para un proceso, POSIX deja indefinido
cuál es entregada  en  primer  lugar.   Linux,  como  otras  muchas  implementaciones,  da
prioridad a las señales estándar en este caso.

Según  POSIX,  una  implementación  debería  permitir que pudieran entrar en la cola de un
proceso al menos _POSIX_SIGQUEUE_MAX (32) señales en tiempo real.  Sin embargo,  en  lugar
de  establecer un límite por proceso, Linux impone un límite para todo el sistema sobre el
número de señales en tiempo real que puede haber en la cola para todos los procesos.  Este
límite  puede  ser  consultado  (y  con  privilegios)  modificado  a  través  del  fichero
/proc/sys/kernel/rtsig-max.  Un fichero relacionado, /proc/sys/kernel/rtsig-nr, puede  ser
usado para averiguar cuántas señales en tiempo real están actualmente en cola.

*/
