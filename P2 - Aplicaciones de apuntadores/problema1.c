/*
*  Realizar un programa que ilustre la relación de dos variables u y v, sus
*  correspondientes direcciones y sus punteros asociados *pu y *pv
*
*  pu es un puntero a u y pv es un puntero a v. Por ejemplo, al ejecutar este
*  programa podría producirse la siguiente salida:

*   u = 3, &u = ef8e, pu = ef8e, *pu = 3
*   v = 3, &v = ef8c, pv = ef8c, *pv = 3
*
*  La variable u representa el valor 3 que debe especificarse en la sentencia de
*  declaración. Al puntero pu se le asigna la dirección de u; a v se le asigna el
*  valor de *pu, y a pv se le asigna la dirección de v.
*
*  Además el programa debe tener los siguientes literales:
*  a) Usar datos enteros, y asignar el valor inicial u=3
*  b) Usar datos en punto flotante, y asignar el valor inicial u=0.3
*  c) Usar caracteres, y asignar el valor inicial u='c'
*/

#include <stdio.h>
#include <math.h>

int main(){
    int u_int = 3;
    int *pu_int = &u_int;
    int v_int = *pu_int;
    int *pv_int = &v_int;

    // a)
    printf("\nu = %d, &u = %p, pu = %p, *pu = %d\n", u_int, &u_int, pu_int, *pu_int);
    printf("v = %d, &v = %p, pv = %p, *pv = %d\n", v_int, &v_int, pv_int, *pv_int);

    // b)
    float u_float = 0.3;
    float *pu_float = &u_float;
    float v_float = *pu_float;
    float *pv_float = &v_float;

    printf("\nu = %f, &u = %p, pu = %p, *pu = %f\n", u_float, &u_float, pu_float, *pu_float);
    printf("v = %f, &v = %p, pv = %p, *pv = %f\n", v_float, &v_float, pv_float, *pv_float);

    // c)
    char u_char = 'C';
    char *pu_char = &u_char;
    char v_char = *pu_char;
    char *pv_char = &v_char;

    printf("\nu = %c, &u = %p, pu = %p, *pu = %c\n", u_char, &u_char, pu_char, *pu_char);
    printf("v = %c, &v = %p, pv = %p, *pv = %c\n\n", v_char, &v_char, pv_char, *pv_char);

    return 0;
}