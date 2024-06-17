/*
*  Hacer un programa, utilizando arreglos, que haga lo siguiente:
*  El programa deberá llenar un arreglo de 99 elementos, el llenado deberá ser
*  usando funciones generadoras de números aleatorios en el rango de (0 a 10).
*  Cuando el arreglo esté generado y lleno, el programa deberá generar la
*  siguiente salida:
*
*  NUMERO       FRECUENCIA      HISTOGRAMA
*    1              1           *
*    2              3           ***
*    3              4           ****
*    4              5           *****
*    5              8           ********
*    6              9           *********
*    7              23          ***********************
*    8              27          ***************************
*    9              19          *******************
*  LA MODA ES EL VALOR MAS FRECUENTE.
*  PARA ESTA EJECUCION LA MODA ES 8 LA CUAL OCURRIO 27 VECES.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int arreglo[99], frecuencias[9];
    printf("\n\t\tArreglo:\n\n\t");
    for (int i = 0; i < 99; i++){
        arreglo[i]=1+rand()%9;
        printf("%d  ", arreglo[i]);
        if ((i+1)%20==0)
            printf("\n\t");
    }
    for (int i = 0; i < 9; i++)
        frecuencias[i]=0;

    for (int i = 0; i < 99; i++){
        for (int j = 1; j <= 9; j++){
            if (arreglo[i] == j)
                frecuencias[j-1]++;
        }
    }
    printf("\n\n\n\n\t NUMERO \t FRECUENCIA \t HISTOGRAMA\n\n");
    for (int i = 0; i < 9; i++){
        printf("\t %3d \t\t %5d \t\t", i+1, frecuencias[i]);
        for (int j = 0; j < frecuencias[i]; j++)
            printf(" *");
        printf("\n");
    }
    printf("\n\n\t LA MODA ES EL VALOR MAS FRECUENTE.");
    int moda, mayor=0;
    for (int i = 0; i < 9; i++){
        if (frecuencias[i] > mayor){
            mayor = frecuencias[i];
            moda = i+1;
        }
        
    }
    printf("\n\t PARA ESTA EJECUCION LA MODA ES %d LA CUAL OCURRIO %d VECES. \n", moda, frecuencias[moda-1]);
    
    return 0;
}