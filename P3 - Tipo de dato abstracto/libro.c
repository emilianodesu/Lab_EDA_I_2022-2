/*
*  Implementar las siguientes estructuras cada una en un programa, e inicializar
*  una variable de estructura en cada caso, además de utilizar el operador flecha
*  para acceder a los miembros de estructura en cada caso.
*  Cada programa debe solicitar valores para inicializar a la estructura e
*  imprimir dichos valores.
*
*  struct libro{
*     char titulo[40];
*     char autor[30];
*     char editorial[20];
*     int anyo;
*  }
*/

#include <stdio.h>

typedef struct libro{
    char titulo[40];
    char autor[30];
    char editorial[20];
    int anyo;
}libro;

void pideDatos(libro *);
void imprimeDatos(libro *);

int main(){
    libro libro1;
    pideDatos(&libro1);
    imprimeDatos(&libro1);

    return 0;
}

void pideDatos(libro *lib_ptr){
    printf("\nIngresa el titulo del libro: ");
    setbuf(stdin,NULL);
    gets(lib_ptr -> titulo);
    printf("Ingresa el autor del libro: ");
    setbuf(stdin,NULL);
    gets(lib_ptr -> autor);
    printf("Ingresa la editorial del libro: ");
    setbuf(stdin,NULL);
    gets(lib_ptr -> editorial);
    printf("Ingresa el anyo del libro: ");
    scanf("%d", &lib_ptr -> anyo);
}

void imprimeDatos(libro *lib_ptr){
    printf("\n\nEl titulo del libro es: %s\n", lib_ptr -> titulo);
    printf("El autor del libro es: %s\n", lib_ptr -> autor);
    printf("La editorial del libro es: %s\n", lib_ptr -> editorial);
    printf("El anyo del libro es: %d\n\n\n", lib_ptr -> anyo);
}