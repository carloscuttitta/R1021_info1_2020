#include <stdio.h>

#define     __R            volatile const     // !< Modificador para solo lectura
#define     __W     	   volatile 	      // !<  Modificador para solo escritura
#define     __RW           volatile           // !< Modificador lectura / escritura

typedef	unsigned int        uint32_t;
typedef	short unsigned int  uint16_t;
typedef	unsigned char       uint8_t;
typedef	int                 int32_t;
typedef	short int           int16_t;
typedef	char                int8_t;

#define     PORT0           0
#define     PORT1           1
#define     PORT2           2
#define     PORT3           3
#define     PORT4           4

#define     FUNCION0        0
#define     FUNCION1        1
#define     FUNCION2        2
#define     FUNCION3        3

void SetPINSEL (uint8_t port , uint8_t bit , uint8_t modo );

uint32_t PINSEL[ 10 ] = {0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff, 
                        0xffffffff};

int main(void)
{
    SetPINSEL ( PORT0 , 26 , FUNCION2 );
    SetPINSEL ( PORT1 , 7  , FUNCION0 );
    SetPINSEL ( PORT2 , 17 , FUNCION1 );
    SetPINSEL ( PORT3 , 15 , FUNCION2 );
    SetPINSEL ( PORT4 , 20 , FUNCION0 );

    printf( "PINSEL1 = 0x%08x\n" , PINSEL[ PORT0 * 2 + 26 / 16 ] );
    printf( "PINSEL2 = 0x%08x\n" , PINSEL[ PORT1 * 2 + 7 / 16 ] );
    printf( "PINSEL5 = 0x%08x\n" , PINSEL[ PORT2 * 2 + 17 / 16 ] );
    printf( "PINSEL6 = 0x%08x\n" , PINSEL[ PORT3 * 2 + 15 / 16 ] );
    printf( "PINSEL9 = 0x%08x\n" , PINSEL[ PORT4 * 2 + 20 / 16 ] );

    return 0;
}

void SetPINSEL (uint8_t port , uint8_t bit , uint8_t modo )
{

//    volatile uint32_t * PINSEL = (volatile uint32_t *) 0x4002C000UL;

    uint32_t mascara ;

// Limpiar poner 00 en el lugar a escribir
    
//    printf( "0:0x%08x\n" ,   bit   );
//    printf( "1:0x%08x\n" , (  bit % 16)  );         // 16 es 0x0010
//    printf( "2:0x%08x\n" , ( ( bit % 16) * 2) );


    mascara = ~(3 << ( ( bit % 16) * 2) );  //~ hace el complemento A1
//    printf( "3:0x%08x\n" , mascara);

//    printf( "4:0x%08x\n" , port * 2 + bit / 16);
    PINSEL[ port * 2 + bit / 16 ] = PINSEL[ port * 2 + bit / 16 ] & mascara;
// 31 30 29 28  27 26 25 24  23 22 21 20  19 18 17 16  15 14 13 12  11 10 09 08  07 06 05 04  03 02 01 00                                           
//  0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  1  1    
//  0  0  0  0   0  0  0  0   0  0  1  1   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0    
//  1  1  1  1   1  1  1  1   1  1  0  0   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1    
//  PINSEL[ port * 2 + bit / 16 ] = 0xffcfffff

    mascara = ( modo << (( bit % 16) * 2));

// 31 30 29 28  27 26 25 24  23 22 21 20  19 18 17 16  15 14 13 12  11 10 09 08  07 06 05 04  03 02 01 00                                           
//  0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  1  0    
//  0  0  0  0   0  0  0  0   0  0  1  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0    
    
//    printf( "5:0x%08x\n" , mascara);

// 31 30 29 28  27 26 25 24  23 22 21 20  19 18 17 16  15 14 13 12  11 10 09 08  07 06 05 04  03 02 01 00                                           
//  0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  1  0    
//  0  0  0  0   0  0  0  0   0  0  1  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0    
//  1  1  1  1   1  1  1  1   1  1  0  1   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1    
    
    
    PINSEL[ port * 2 + bit / 16 ] = PINSEL[ port * 2 + bit / 16 ] | mascara;

// 31 30 29 28  27 26 25 24  23 22 21 20  19 18 17 16  15 14 13 12  11 10 09 08  07 06 05 04  03 02 01 00                                           
//  1  1  1  1   1  1  1  1   1  1  0  0   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1    
//  0  0  0  0   0  0  0  0   0  0  1  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0   0  0  0  0    
//  1  1  1  1   1  1  1  1   1  1  1  0   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1   1  1  1  1    
   
}
