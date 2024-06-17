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

void printQueue(AGENDAPTR);
int isEmpty(AGENDAPTR);
char dequeue(AGENDAPTR *, AGENDAPTR *);
void enqueue(AGENDAPTR *, AGENDAPTR *, char, char[25], char[25], char[25], char, int, char[69],char[35], char[12]);
void instructions(void);

int main(){
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
            enqueue(&headPtr, &tailPtr, id, nombre1, ap_p, ap_m, sexo, edad1, domicilio1, correo1, telefono);
            printQueue(headPtr);
            break;
        
        case 2:
            if (!isEmpty(headPtr)){
                item = dequeue(&headPtr, &tailPtr);
                printf("Se elimino el ID %c.\n",item);
            }
            printQueue(headPtr);
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

void enqueue(AGENDAPTR *headPtr, AGENDAPTR *tailPtr, char id, char nombre[25] , char ap_pa[25], char ap_ma[25], char sexo, int edad, char domicilio[69], char correo[35], char telefono[12]){
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

        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr))
            *headPtr = newPtr;
        else
            (*tailPtr)->nextPtr = newPtr;
        *tailPtr = newPtr;
    }
    else
        printf("ID %c NO SE PUDO AGREGAR. NO HAY MEMORIA DISPONIBLE.\n", id);
}

char dequeue(AGENDAPTR *headPtr, AGENDAPTR *tailPtr){
    char value;
    AGENDAPTR tempPtr;
    value = (*headPtr)->id;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL)
        *tailPtr = NULL;
    free(tempPtr);
    return value;
}

int isEmpty(AGENDAPTR headPtr){
    return headPtr == NULL;
}

void printQueue(AGENDAPTR currentPtr){
    if (currentPtr == NULL)
        printf("LA COLA ESTA VACIA.\n\n");
    else{
        printf("\n\nLA COLA ES:\n\n");
        while (currentPtr != NULL){
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
        printf("NULL\n\n");
    }
}

