#include <stdint.h>

int main () 
{
    volatile uint8_t* reg_MCUCR = (volatile uint8_t*) 0x55;
	//Para registro PC2
    volatile uint8_t* salidaPORTC = (volatile uint8_t*) 0x28;
    volatile uint8_t* salidaDDRC = (volatile uint8_t*) 0x27;
    volatile uint8_t* salidaPINC = (volatile uint8_t*) 0x26;

    //Para el puerto PB5
    volatile uint8_t* configDDRB = (volatile uint8_t*) 0x24;
	volatile uint8_t* salidaB = (volatile uint8_t*) 0x25;
    /*SETUP*/
    //Colocar bit 4 en alta
    *reg_MCUCR |= (1<<4);
    //d
    *salidaPORTC |= (1<<2);
    //e
    *salidaDDRC &= ~(1<<2);
	//f.El valor inicial del pin 5 en baja
	*salidaB &= ~(1<<5); 
    //g. Configurar B como salida
	*configDDRB |= (1<<5);

    while (1)
    {   
        if (*salidaPINC & (1<<2))
        {   
            //colocar en alta el bit 5
            *salidaB |= (1<<5);
        }else{
            *salidaB &= ~(1<<5); 
        }
        
    }
    
    return 0;
}