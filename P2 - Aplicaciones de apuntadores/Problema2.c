/*
*  Realizar un programa que inicialice la variable v con el valor de 5 y asignar
*  la dirección de v a la variable puntero pv. Utilizar la funcion printf() para
*  mostrar los valores actuales de *pv y v. Luego el valor de *pv es puesto a 0.
*/

#include <stdio.h>

int main(){
    int v = 5;
    int *pv = &v;
    printf("*pv = %d, v = %d\n", *pv, v);

    *pv = 0;
    printf("*pv = %d, v = %d", *pv, v);

    return 0;
}