/* Realizar una calculadora que solo realice las operaciones (+); (-); (x) y (/) ingresando los dados por línea de comando de la siguiente forma:  ./calculadora numero1 operador numero2. Por ejemplo 
 ./calculadora 12,4 + 2,1  Por default los considera como positivo a los números ingresado, de lo contrario lo tiene que indicar. Ejemplo ./calculadora -20,5 x 2,4
*/

#include"my.h"

int main (int argc , char ** argv)
{
    float op1,op2;
    int i,V1[3],V2[3];    // V[0] cantidad antes de la coma  
                          // V[1] cantidad despues de la coma
                          // V[2] vale 1 si es negativo
    char *p;

    if (argc == 4)
    {
        verificarComa( V1 , *(argv+1) );        
        verificarComa( V2 , *(argv+3) );        
        if ( (V1[0] >= 0) && (V2[0] >= 0) ){
            op1=myAtof ( V1 , *(argv+1));
            op2=myAtof ( V2 , *(argv+3));
            p=*(argv+2);
            for (i=0 ; *(p+i) != '\0' ; i++){
            }
            if (i == 1)
            {
                switch (*p)
                {
                    case '+':
                        printf("la suma es %0.3f \n",op1+op2);  
                        break;
                    case '-':
                        printf("la resta es %0.3f \n",op1-op2);         
                        break;
                    case 'x':
                        printf("el producto es %0.3f \n",op1*op2);         
                        break;
                    case '/':
                        printf("la división es %0.3f \n",op1/op2);         
                        break;
                    default :
                        printf("ingrese un operador valido\n");         
                        break;
                }
            }else{
                        printf("ingrese un operador valido\n");         
            }                
        }else {
            printf("ingresar solo numeros y a lo sumo una sola coma\n");
        }
    }else{
        printf("ingrese los parametros correctos\n");
    }
   return 0;
}

