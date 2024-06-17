/*
*  Deseamos hacer un listado de precios de los artículos de la empresa
*  QUIEBRA, S.A. Los datos a procesar para cada artículo son los siguientes:
*     o Código del artículo: cadena de 3 caracteres.
*     o Descripción: Cadena de 40 caracteres.
*     o Componentes: Matriz de 5 elementos. Cada elemento de esta matriz
*       contendrá los siguientes campos:
*          1. Código del componente: Cadena de 8 caracteres.
*          2. Cantidad: Entero entre 1 y 100.
*          3. Precio unitario: Entero entre 500 y 5000.
*  Construye un programa que realice las siguientes tareas:
*     a) Capturar por teclado los datos de los artículos, almacenándolos en una
*        matriz (máximo 25 artículos).
*     b) Imprimir los datos de la matriz con formato
*/

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_COMPONENTES 5

typedef struct componente{
    char cod[9];
    int cantidad;
    int precio_u;
}COMPONENTES;

typedef struct articulo{
    char codigo[4];
    char descripcion[41];
    COMPONENTES c[5];
}ARTICULO;

void clrscr();
void ingresaDatos(ARTICULO *a_ptr);
void imprimeArticulo(ARTICULO *a_ptr);

int main(){
    int num_arts;
    do{
        printf("Ingrese numero de articulos (max 25): ");
        scanf("%d",&num_arts);
        if (num_arts>25 || num_arts<1)
            printf("ERROR: NUMERO INVALIDO\n\n");
    } while (num_arts>25 || num_arts<1);
    
    ARTICULO arts[num_arts];
    int i;
    for ( i = 0; i < num_arts; i++){
        printf("\nArticulo %d\n",i+1);
        ingresaDatos(&arts[i]);
    }
    
    clrscr();

    printf("\nQUIEBRA, S.A. Listado de precios                                     Pagina:001");
    printf("\n\n%68s","COMPONENTES");
    printf("\n%79s","--------------------------------");
    printf("\nCod  %-40s  %-8s  %-5s  %-6s  %-7s\n","Descripcion","Codigo","Cant","Precio","Importe");
    for (i = 0; i < 79; i++)
        printf("-");

    for ( i = 0; i < num_arts; i++)
        imprimeArticulo(&arts[i]);

    return 0;
}

void ingresaDatos(ARTICULO *a_ptr){
    printf("\nCodigo: ");
    setbuf(stdin, NULL);
    gets(a_ptr->codigo);
    printf("Descripcion: ");
    setbuf(stdin, NULL);
    gets(a_ptr->descripcion);
    int i;
    for ( i = 0; i < CANTIDAD_COMPONENTES; i++){
        printf("\nComp %d.\n",i+1);
        printf("Codigo de comp.: ");
        scanf("%s",&a_ptr->c[i].cod);
        printf("Cantidad: ");
        scanf("%d",&a_ptr->c[i].cantidad);
        printf("Precio unitario: $");
        scanf("%d",&a_ptr->c[i].precio_u);
    }
}
void imprimeArticulo(ARTICULO *a_ptr){
    printf("\n%s  %-40s  %-8s  %-5d  $%-5d  $%-6d\n", a_ptr->codigo, a_ptr->descripcion, a_ptr->c[0].cod, a_ptr->c[0].cantidad, a_ptr->c[0].precio_u, (a_ptr->c[0].precio_u)*(a_ptr->c[0].cantidad));
    int i,suma = 0;
    for ( i = 1; i < CANTIDAD_COMPONENTES; i++){
        printf("%45s  %-8s  %-5d  $%-5d  $%-6d\n"," ", a_ptr->c[i].cod, a_ptr->c[i].cantidad, a_ptr->c[i].precio_u, (a_ptr->c[i].precio_u)*(a_ptr->c[i].cantidad));
    }
    for ( i = 0; i < CANTIDAD_COMPONENTES; i++){
        suma += (a_ptr->c[i].cantidad * a_ptr->c[i].precio_u);
    }
    printf("\n%79s","---------");
    printf("\n%70s  $%-6d\n\n","Total:",suma);
}

void clrscr(){
    system("@cls||clear");
}