/*
*  Escribe un programa que lea dos numeros enteros del teclado y presente en pantalla
*  el triple de la diferencia entre el mayor y el menor. (Utiliza el operador ternario).
*/
#include<stdio.h>

int main(){
    int num_1, num_2;

    printf("Escribe dos numeros enteros: ");
    scanf("%d %d",&num_1,&num_2);
    printf("%d", num_1 > num_2 ? 3*(num_1-num_2) : 3*(num_2-num_1));

    return 0;
}
