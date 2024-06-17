#include <stdio.h>

int  main(){
    struct computadora{
        float costo;
        int anio;
        int velocidad_cpu;
        char tipo_cpu[16];
    }modelo;

    printf("Tipo de cpu\n");
    gets(modelo.tipo_cpu);
    printf("Velocidad de la cpu\n");
    scanf("%d", &modelo.velocidad_cpu);
    printf("Anio de fabricacion\n");
    scanf("%d", &modelo.anio);
    printf("Precio\n");
    scanf("%f", &modelo.costo);    

    printf("Estos son los datos que introdujo\n");
    printf("Anio: %d\n", modelo.anio);
    printf("Costo: $%6.2f\n", modelo.costo);
    printf("Tipo CPU: %s\n", modelo.tipo_cpu);
    printf("Velocidad CPU: %d", modelo.velocidad_cpu);

    return 0;
}