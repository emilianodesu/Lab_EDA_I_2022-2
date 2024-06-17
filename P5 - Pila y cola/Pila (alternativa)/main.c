#include <stdio.h>
#include <stdlib.h>
#include "StackChar.h"

int menu(){   
    int menu=0;
    printf("Ingrese el número de la operación que desea realizar:\n");
    printf("1. Crear una pila nueva.\n");
    printf("2. Agregar elemento a la pila.\n");
    printf("3. Extraer elemento de la pila.\n");
    printf("4. Ver el elemento superior de la pila.\n");
    printf("5. Verificar si la pila está vacia.\n");
    printf("6. Verificar si la pila está llena.\n");
    printf("7. Destruir la pila.\n");
    printf("8. Terminar ejecución.\n");
    
    scanf("%d",&menu);
    return menu;
}


int main(){
    int opcion;
    int tam;
    char c;
    int bandera=1;
    StackChar *pila;
    while(bandera==1){
        opcion=menu(); 
        switch(opcion){
            case 1:
                printf("Ingrese el tamanio de la pila: ");
                scanf("%d",&tam);
                pila=StackChar_New(tam);
                printf("La pila fue creada.\n");
                break;
            case 2:
                printf("Ingrese el elemento:\n ");
                scanf("%s",&c);
                StackChar_Push(pila,c);
                printf("El elemento se agregó.\n");
                break;
            case 3:
                c=StackChar_Pop(pila);
                printf("El elemento es (POP): %c \n",c);
                break;
            case 4:
                c=StackChar_Peek(pila);
                printf("El elemento es (PEEK): %c\n",c);
                break;
            case 5:
                if(StackChar_IsEmpty(pila)==true){
                    printf("La pila esta vacía.\n");
                }else{
                    printf("La pila no esta vacía.\n");
                }
                break;
            case 6:
                if(StackChar_IsFull(pila)==true){
                    printf("La pila está llena.\n");
                }else{
                    printf("La pila no esta llena.\n");
                }
                break;
            case 7:
                StackChar_Delete(pila);
                printf("La pila fue destruida.\n");
                break;
            case 8:
                bandera==0;
                printf("Salimos de ejecución.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    }
    StackChar_Delete(pila);
    return 0;
}
