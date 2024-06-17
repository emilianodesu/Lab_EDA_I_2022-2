/*
*  Realizar un programa que lea el numero de términos n para calcular la suma (n!)^1/3
*  Elaborar dos funciones, para la sumatoria y para el factorial.
*/

#include <stdio.h>
#include <math.h>

int factorial(int num);
double suma(int n);

int main(){
    int n;

    printf("\nIngresa el numero de terminos para la suma, n = ");
    scanf("%d",&n);
    printf("\nLa suma de los primeros %d terminos es %lf\n\n",n,suma(n));

    return 0;
}

int factorial(int num){
    if (num == 1)
        return (1);
    else
        return (num * factorial(num-1));
}

double suma(int n){
    double suma = 0;
    for (int i = 1; i <= n; i++)
        suma += pow((double)factorial(i),(double)1/3);
    return suma;
}

