#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bool.h"
#include "dll.h"
//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main(void){
    dll *lista = dll_New();

    int elem = 0;
    int elemen = 0;
    int find = 0;

    while (1){
        switch (menu()){
        case 0:
            dll_Delete(lista);
            exit(0);
            break;
        case 1:
            printf("Ingrese el elemento que desea agregar a la lista: \n");
            scanf("%d", &elem);
            dll_InsertBack(lista, elem);
            break;
        case 2:
            printf("Ingrese el elemento que desea agregar a la lista: \n");
            scanf("%d", &elemen);
            dll_InsertFront(lista, elemen);
            break;
        case 3:
            printf("El elemento del extremo posterior es: %d \n", dll_RemoveBack(lista));
            break;
        case 4:
            printf("El elemento del extremo anterior es: %d \n", dll_RemoveFront(lista));
            break;
        case 5:
            printf("Ingrese el valor que desea buscar en la lista: \n");
            scanf("%d", &find);
            if (dll_FindIf(lista, find) == true){
                printf("El valor %d se encuentra en la lista.\n", find);
            }
            else{
                printf("El valor %d no se encuentra en la lista.\n", find);
            }
            break;
        case 6:
            if (dll_IsEmpty(lista) == true){
                printf("La lista esta vacia.\n");
            }else
                printf("La lista no esta vacia. \n");
            break;
        case 7:
            dll_Purge(lista);
            printf("Lista vacía.\n");
            break;
        default:
            printf("Opcion no valida.\n");
        }
    }
    dll_Delete(lista);

    return 0;
}