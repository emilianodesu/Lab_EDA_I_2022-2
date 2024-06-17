#include <stdio.h>

struct computadora{
    float costo;
    int anio;
    int velocidad_cpu;
    char tipo_cpu[16];
};

typedef struct computadora EC;
EC RecibeDatos(EC s);

int  main(){
    EC modelo;
    modelo = RecibeDatos(modelo);
    printf("Estos son los datos que introdujo\n");
    printf("Anio: %d\n", modelo.anio);
    printf("Costo: $%6.2f\n", modelo.costo);
    printf("Tipo CPU: %s\n", modelo.tipo_cpu);
    printf("Velocidad CPU: %d", modelo.velocidad_cpu);

    return 0;
}

EC RecibeDatos(EC s){
    printf("Tipo de cpu\n");
    gets(s.tipo_cpu);
    printf("Velocidad de la cpu\n");
    scanf("%d", &s.velocidad_cpu);
    printf("Anio de fabricacion\n");
    scanf("%d", &s.anio);
    printf("Precio\n");
    scanf("%f", &s.costo);    

    return s;
}