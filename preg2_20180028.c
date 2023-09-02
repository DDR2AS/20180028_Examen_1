#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ImprimirArreglo(int arregloNumeros[]); 
void inicializar_arreglo (int array[]);
void Imprimir_Resultado(int num, int sumaDiv);

int main ()
{
    int arrayNum[15];
    //Variables para algoritmo
    int sumaDivisores[15];
    
    inicializar_arreglo(arrayNum);
    inicializar_arreglo(sumaDivisores);
    
    //Se va a rellenar con datos aleatorios
    srand(time(0));
    for (int i = 0; i < 15; i++){
        arrayNum[i] = rand()%31;
    }
    
    ImprimirArreglo(arrayNum);
    //ANALIZAR DIVISORES

    /*Bucle 1: Recorrer cada número del arreglo*/
    /*Bucle 2: Analizar divisores*/
    for (int j = 0; j < 15; j++){
        int divisor=0;
        int cont = 0;
        do
        {
            divisor  = arrayNum[j]-cont;
            if(arrayNum[j]%divisor==0 && divisor != arrayNum[j])
            {
            //printf("%d es divisor de %d\n", divisor, arrayNum[j]);
            sumaDivisores[j] += divisor;
            }
            cont++;
        }
        while(cont!=(arrayNum[j]));

        Imprimir_Resultado(arrayNum[j], sumaDivisores[j]);
    }
    return 0;
}

void inicializar_arreglo(int array[]){
    int contador = 0;
    while (contador <15)
    {
        array[contador] = 0;
        contador++;
    }
}

void ImprimirArreglo(int arregloNumeros[]){
    int contador = 0;
    printf("El arreglo es ");
   
   while (contador < 15)
    {
        printf("%d",arregloNumeros[contador]);
        if (contador <14){
            printf(",");
        }
        contador++;
    }
    printf("\n\n");
}

void Imprimir_Resultado(int num, int sumaDiv){
    
    if (sumaDiv<num){
            printf("%d - Deficiente\n",num);
        }else{
            if (sumaDiv==num){
                printf("%d - Perfecto\n",num);
            }else printf("%d - Abundante\n",num);
    }
}