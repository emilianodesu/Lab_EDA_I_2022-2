#include <stdio.h>
#include "queue.h"

int main(){
    int opcion, tam;
    QueueInt* p;
    int dato, bandera;
    bandera=1;
    while(bandera){
        printf("1. Crear cola\n");
        printf("2. Agregar elemento.\n");
        printf("3. Remover elemento.\n");
        printf("4. Ver elemento.\n");
        printf("5. La cola está llena.\n");
        printf("6. La cola está vacía.\n");
        printf("7. Eliminar cola.\n");
        printf("8. Salir.\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Ingrese el tamaño.\n");
                scanf("%d",&tam);
                p=QueueInt_New(tam);
                printf("Cola creada.\n");
                break;
            case 2:
                printf("Agregar elemento: ");
                scanf("%d",&dato);
                QueueInt_Insert(p,dato);
                break;
            case 3:
                printf("El elemento es: %d \n",QueueInt_Remove(p));
                break;
            case 4:
                printf("El elemento es: %d \n",QueueInt_Peek(p));
                break;
            case 5:
                if(QueueInt_IsFull(p)==true){
                    printf("La cola esta llena.\n");
                }else{
                    printf("La cola no está llena.\n");
                }
                break;
            case 6:
                if(QueueInt_IsEmpty(p)==true){
                    printf("La cola esta vacia.\n");
                }else{
                    printf("La cola no esta vacía.\n");
                }
                break;
            
            case 7:
                QueueInt_Delete(p);
                break;
            case 8:
                printf("Termina ejecucion.\n");
                bandera=0;
                break;
            
            default:
                printf("opcion no valida.\n");
                break;
        }
    }
    QueueInt_Delete(p);

    return 0;
}
