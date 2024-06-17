#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

struct ALUMNO{
	char id[12];
	char nombre[25];
	char apellido_paterno[25];
	char apellido_materno[25];
    int edad;
    char domicilio[69];
    char correo[35];
    struct ALUMNO *nextPtr; 
};
typedef struct ALUMNO alumno;
typedef alumno *alumnoptr;

void push(alumnoptr *, char[12], char[25], char[25], char[25], int, char[69], char[35]); 
void pop(alumnoptr *);
int isEmpty(alumnoptr);
void printStack(alumnoptr);
void instructions(void);

int main(){
    alumnoptr stackPtr = NULL;
    char id_alumno[12], nombre1[25], ap_p[25], ap_m[25], domicilio1[69], correo1[35];
	int edad1, choice;

    instructions();
    printf("? ");
    scanf("%d",&choice);

    while (choice != 3){
        switch (choice){
        case 1:
            printf("\nIngrese datos del alumno: \n");
            printf("ID: ");
            setbuf(stdin,NULL);
            scanf("%s", id_alumno);
            printf("NOMBRE: ");
            setbuf(stdin,NULL);
            scanf("%s", nombre1);
            printf("APELLIDO PATERNO: ");
            setbuf(stdin,NULL);
            scanf("%s", ap_p);
            printf("APELLIDO MATERNO: ");
            setbuf(stdin,NULL);
            scanf("%s", ap_m);
            printf("EDAD: ");
            setbuf(stdin,NULL);
            scanf("%d", &edad1);
            printf("DOMICILIO: ");
            setbuf(stdin,NULL);
            gets(domicilio1);
            printf("CORREO: ");
            setbuf(stdin,NULL);
            scanf("%s", correo1);
            push(&stackPtr, id_alumno, nombre1, ap_p, ap_m, edad1, domicilio1, correo1);
            printStack(stackPtr);
            break;
        case 2:
            if (!isEmpty(stackPtr))
                pop(&stackPtr);
            printStack(stackPtr);
            break;
        default:
            printf("OPCION INVALIDA. INTENTE DE NUEVO.\n\n");
            instructions();
            break;
        }
        printf("? ");
        scanf("%d", &choice);
    }
    printf("FIN DE LA EJECUCION.\n");
    
    return 0;
}

void instructions (void){
    printf("SELECCIONE UNA OPCION:\n"
    "1 PARA AGREGAR A UN ALUMN@ A LA PILA\n"
    "2 PARA ELIMINAR A UN ALUMN@ DE LA PILA\n"
    "3 PARA TERMINAR EL PROGRAMA\n");
}

void push(alumnoptr *topPtr, char id_a[12], char nombre2[25], char ap_pa[25], char ap_ma[25], int edad2, char domicilio2[69], char correo2[35]){
    alumnoptr newPtr;
    newPtr = malloc(sizeof(alumno));
    if (newPtr != NULL){
        strcpy(newPtr->id, id_a);
        // newPtr->id = id_a;
        strcpy(newPtr->nombre, nombre2);
        strcpy(newPtr->apellido_paterno, ap_pa);
        strcpy(newPtr->apellido_materno, ap_ma);
        newPtr->edad = edad2;
        strcpy(newPtr->domicilio, domicilio2);
        strcpy(newPtr->correo, correo2);
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
        printf("%s NO SE HA AÑADIDO. NO EXISTE MEMORIA DISPONIBLE.\n", nombre2);
}

void pop(alumnoptr *topPtr){
    alumnoptr tempPtr;
    tempPtr = *topPtr;
    char popValue[12];
    strcpy(popValue, (*topPtr)->id);
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    printf("EL ALUMN@ QUE SALIO DE LA PILA ES ID: %s.\n", popValue);
}

void printStack(alumnoptr currentPtr){
    if (currentPtr == NULL)
        printf("LA PILA SE ENCUENTRA VACIA.\n\n");
    else{
        printf("\n\nLA PILA QUEDA CONFORMADA DE LA SIGUIENTE FORMA:\n\n");
        while (currentPtr != NULL){
            printf("ID: %s\n", currentPtr->id);
            printf("NOMBRE: %s\n",currentPtr->nombre);
            printf("APELLIDO PATERNO: %s\n",currentPtr->apellido_paterno);
            printf("APELLIDO MATERNO: %s\n",currentPtr->apellido_materno);
            printf("EDAD: %d\n",currentPtr->edad);
            printf("DOMICILIO: %s\n",currentPtr->domicilio);
            printf("CORREO: %s\n",currentPtr->correo);
            printf(" |\n");
            printf(" |\n");
            printf(" v\n\n");
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

int isEmpty(alumnoptr topPtr){
    return topPtr == NULL;
}
