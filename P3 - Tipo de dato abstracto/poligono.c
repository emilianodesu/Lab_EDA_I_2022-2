/*
*  Implementar las siguientes estructuras cada una en un programa, e inicializar
*  una variable de estructura en cada caso, además de utilizar el operador flecha
*  para acceder a los miembros de estructura en cada caso.
*  Cada programa debe solicitar valores para inicializar a la estructura e
*  imprimir dichos valores.
*
*  struct poligono{
*     char nombre[20];
*     int lados;
*     float longitudLado, area;
*  }
*/

#include <stdio.h>

typedef struct poligono{
    char nombre[20];
    int lados;
    float longitudLado, area;
}poligono;

void pideDatos(poligono *poli_ptr);
void imprimeDatos(poligono *poli_ptr);

int main(){
    poligono poligono1;
    pideDatos(&poligono1);
    imprimeDatos(&poligono1);

    return 0;
}

void pideDatos(poligono *poli_ptr){
    printf("\nIngresa el nombre del poligono: ");
    setbuf(stdin,NULL);
    gets(poli_ptr -> nombre);
    printf("Ingresa la cantidad de lados del poligono: ");
    scanf("%d", &poli_ptr -> lados);
    printf("Ingresa la longitud de los lados: ");
    scanf("%f",&poli_ptr -> longitudLado);
    printf("Ingresa el area del poligono: ");
    scanf("%f",&poli_ptr -> area);
}

void imprimeDatos(poligono *poli_ptr){
    printf("\n\nEl poligono es un: %s\n", poli_ptr -> nombre);
    printf("El poligono tiene %d lados\n", poli_ptr -> lados);
    printf("La longitud de los lados es: %.2f\n", poli_ptr -> longitudLado);
    printf("El area del poligono es: %.2f\n\n\n", poli_ptr -> area);
}