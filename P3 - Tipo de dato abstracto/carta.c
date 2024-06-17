/*
*  Implementar las siguientes estructuras cada una en un programa, e inicializar
*  una variable de estructura en cada caso, además de utilizar el operador flecha
*  para acceder a los miembros de estructura en cada caso.
*  Cada programa debe solicitar valores para inicializar a la estructura e
*  imprimir dichos valores.
*
*  struct carta{
*     int numero;
*     char palo;
*  }
*/

#include <stdio.h>

typedef struct carta{
    int numero;
    char *palo;
}carta;

void pideDatos(carta *);
void imprimeDatos(carta *);

int main(){

    carta carta1;
    pideDatos(&carta1);
    imprimeDatos(&carta1);

    return 0;
}

void pideDatos(carta *carta_ptr){
    printf("Ingresa el palo de la carta: ");
    scanf("%s", carta_ptr->palo);
    printf("Ingresa el numero de la carta: ");
    scanf("%d", &carta_ptr->numero);
}

void imprimeDatos(carta *carta_ptr){
    printf("\n\nEl palo de la carta es: %s\n", carta_ptr->palo);
    printf("El numero de la carta es: %d\n\n\n", carta_ptr->numero);
}