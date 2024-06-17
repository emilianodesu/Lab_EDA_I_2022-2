/*
*  Escribe un programa que lea una matriz bidimensional e imprima su transpuesta.
*/
#include<stdio.h>

int main(){
    int m, n;
    printf("Dame el numero de filas: ");
    scanf("%d",&m);
    printf("Dame el numero de columnas: ");
    scanf("%d",&n);
    int mat[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Dame el elemento de las coordenadas %d , %d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            printf("%3d ",mat[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int j = 0; j < n; j++){
        for (int i = 0; i < m; i++)
            printf("%3d ",mat[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
