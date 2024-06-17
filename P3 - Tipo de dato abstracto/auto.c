/*
*  Diseñar e implementar una estructura que se llame auto, y que tenga los
*  elementos de estructura:
*  - Modelo
*  - Marca
*  - Versión
*  - Precio
*  - Tipo de transmisión.
*  - Gasolina, Eléctrico, Híbrido.
*  - Potencia.
*  Y crear 3 variables a partir de esa estructura: Auto 1, Auto 2, Auto 3.
*  Después inicializar esos objetos (desde el teclado), y mostrar para cada
*  uno sus atributos en pantalla de las siguientes formas:
*  - Funciones.
*  - Apuntadores.
*  Y mostrar en cada caso el espacio que ocupa la estructura en memoria.
*/

#include <stdio.h>

typedef struct AUTO{
    char modelo[20];
    char marca[20];
    char version[20];
    int precio;
    char transmision[15];
    char motor[15];
    int potencia;
}AUTO;

void recibeDatos(AUTO *);
void imprimeDatos(AUTO *);
void espacioMemoria(AUTO *);

int main(){

    AUTO auto1, auto2, auto3;
    recibeDatos(&auto1);
    recibeDatos(&auto2);
    recibeDatos(&auto3);
    printf("\n\t\t\t   AUTO 1\n");
    imprimeDatos(&auto1);
    espacioMemoria(&auto1);
    printf("\n\t\t\t   AUTO 2\n");
    imprimeDatos(&auto2);
    espacioMemoria(&auto2);
    printf("\n\t\t\t   AUTO 3\n");
    imprimeDatos(&auto3);
    espacioMemoria(&auto3);

    return 0;
}

void recibeDatos(AUTO *a_ptr){
    printf("\n\n\tIngresa marca: ");
    fflush(stdin);
    gets(a_ptr->marca);
    printf("\tIngresa modelo: ");
    fflush(stdin);
    gets(a_ptr->modelo);
    printf("\tIngresa version: ");
    fflush(stdin);
    gets(a_ptr->version);
    printf("\tIngresa precio: ");
    scanf("%d",&a_ptr->precio);
    printf("\tIngresa tipo de transmision (Automatica/Manual): ");
    fflush(stdin);
    gets(a_ptr->transmision);
    printf("\tIngresa que tipo de motor tiene (Gasolina/Hibrido/Electrico): ");
    fflush(stdin);
    gets(a_ptr->motor);
    printf("\tIngresa potencia: ");
    scanf("%d",&a_ptr->potencia);
}

void imprimeDatos(AUTO *a_ptr){
    printf("\n\n\tModelo es: %s\n",a_ptr->modelo);
    printf("\tMarca es: %s\n",a_ptr->marca);
    printf("\tVersion es: %s\n",a_ptr->version);
    printf("\tPrecio es: $%d.00\n",a_ptr->precio);
    printf("\tTransmision es: %s\n",a_ptr->transmision);
    printf("\tMotor es: %s\n",a_ptr->motor);
    printf("\tPotencia es: %d\n hp",a_ptr->potencia);
}

void espacioMemoria(AUTO *a_ptr){
    printf("\n\n\tEl espacio en memoria es: %zu bytes\n", sizeof(*a_ptr));
}