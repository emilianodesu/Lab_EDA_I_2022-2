#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda{ 
    char id;
	char nombre[25];
	char apellido_paterno[25];
	char apellido_materno[25];
    char sexo;
    int edad;
    char domicilio[69];
    char correo[35];
    char telefono[12];
    struct agenda *nextPtr;
};

typedef struct agenda AGENDA;
typedef AGENDA *AGENDAPTR;

/* PROTOTIPO DE LOS FUNCIONES UTILIZADAS */

void printQueue(AGENDAPTR, int *);
int isEmpty(AGENDAPTR);
char dequeue(AGENDAPTR *, AGENDAPTR *, int *);
void enqueue(AGENDAPTR *, AGENDAPTR *, int *, char, char[25], char[25], char[25], char, int, char[69],char[35], char[12]);
void instructions(void);

int main(){
    int elements = 0;
    AGENDAPTR headPtr = NULL, tailPtr = NULL;
    char sexo, id, nombre1[25], ap_p[25], ap_m[25], domicilio1[69], correo1[35], telefono[12];
    int choice, edad1;
    char item;

    instructions();
    printf("?");
    scanf("%d",&choice);

    while (choice != 3){
        switch (choice){
        case 1:
            printf("\nIngrese datos: \n");
            printf("ID: ");
            setbuf(stdin,NULL);
            scanf("%c", &id);
            printf("NOMBRE: ");
            setbuf(stdin,NULL);
            scanf("%s", nombre1);
            printf("APELLIDO PATERNO: ");
            setbuf(stdin,NULL);
            scanf("%s", ap_p);
            printf("APELLIDO MATERNO: ");
            setbuf(stdin,NULL);
            scanf("%s", ap_m);
            printf("SEXO(H/M): ");
            setbuf(stdin,NULL);
            scanf("%c", &sexo);
            printf("EDAD: ");
            setbuf(stdin,NULL);
            scanf("%d", &edad1);
            printf("DOMICILIO: ");
            setbuf(stdin,NULL);
            gets(domicilio1);
            printf("CORREO: ");
            setbuf(stdin,NULL);
            scanf("%s", correo1);
            printf("TELEFONO (10 digitos): ");
            setbuf(stdin,NULL);
            scanf("%s", telefono);
            enqueue(&headPtr, &tailPtr, &elements, id, nombre1, ap_p, ap_m, sexo, edad1, domicilio1, correo1, telefono);
            printQueue(headPtr, &elements);
            break;
        
        case 2:
            if (!isEmpty(headPtr)){
                item = dequeue(&headPtr, &tailPtr, &elements);
                printf("Se elimino el ID %c.\n",item);
            }
            printQueue(headPtr, &elements);
            break;
        
        default:
            printf("OPCION INVALIDA.\n\n");
            instructions();
            break;
        }
        printf("?");
        scanf("%d", &choice);
    }
    printf("FIN DE LA EJECUCION.\n");
    return 0;
}

void instructions(void){
    printf("INGRESA UNA OPCION:\n"
    "1 para encolar un nuevo elemento\n"
    "2 para desencolar\n"
    "3 para terminar la ejecucion\n");
}

void enqueue(AGENDAPTR *headPtr, AGENDAPTR *tailPtr, int *elementsPtr, char id, char nombre[25] , char ap_pa[25], char ap_ma[25], char sexo, int edad, char domicilio[69], char correo[35], char telefono[12]){
    AGENDAPTR newPtr;
    newPtr = malloc(sizeof(AGENDA));

    if (newPtr != NULL){
        newPtr->id = id;
        strcpy(newPtr->nombre, nombre);
        strcpy(newPtr->apellido_paterno, ap_pa);
        strcpy(newPtr->apellido_materno, ap_ma);
        newPtr->sexo = sexo;
        newPtr->edad = edad;
        strcpy(newPtr->domicilio, domicilio);
        strcpy(newPtr->correo, correo);
        strcpy(newPtr->telefono, telefono);

        if (isEmpty(*headPtr)){
            *headPtr = newPtr;
            newPtr->nextPtr = NULL;
        }
        else{
            newPtr->nextPtr = *headPtr;
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
        (*elementsPtr)++;
    }
    else
        printf("ID %c NO SE PUDO AGREGAR. NO HAY MEMORIA DISPONIBLE.\n", id);
}

char dequeue(AGENDAPTR *headPtr, AGENDAPTR *tailPtr, int *elementsPtr){
    char value;
    AGENDAPTR tempPtr;
    value = (*headPtr)->id;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;
    if (*headPtr == *tailPtr)
        (*tailPtr)->nextPtr = NULL;
    else
        (*tailPtr)->nextPtr = *headPtr;
    free(tempPtr);
    (*elementsPtr)--;
    return value;
}

int isEmpty(AGENDAPTR headPtr){
    return headPtr == NULL;
}


void printQueue(AGENDAPTR currentPtr, int *elementsPtr){
    int i;
    if (currentPtr == NULL)
        printf("LA COLA ESTA VACIA.\n\n");
    else{
        printf("\n\nLA COLA ES:\n");
        for (i = 0; i < *elementsPtr; i++){
            printf("\n(%p)\n", currentPtr);
            printf("ID: %c\n", currentPtr->id);
            printf("NOMBRE: %s\n",currentPtr->nombre);
            printf("APELLIDO PATERNO: %s\n",currentPtr->apellido_paterno);
            printf("APELLIDO MATERNO: %s\n",currentPtr->apellido_materno);
            printf("SEXO: %c\n",currentPtr->sexo);
            printf("EDAD: %d\n",currentPtr->edad);
            printf("DOMICILIO: %s\n",currentPtr->domicilio);
            printf("CORREO: %s\n",currentPtr->correo);
            printf("TELEFONO: %s\n",currentPtr->telefono);
            printf(" |\n");
            printf(" |\n");
            printf(" v\n");
            currentPtr = currentPtr->nextPtr;
        }
        printf("\n(%p)\n", currentPtr);
    }
}