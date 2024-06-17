#include <stdio.h>
#include <stdlib.h>

struct queueNode{ /*Autorreferencia a la estructura*/
    char data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

/* PROTOTIPO DE LOS FUNCIONES UTILIZADAS */

void printQueue(QUEUENODEPTR, int *);
int isEmpty(QUEUENODEPTR);
char dequeue(QUEUENODEPTR *, QUEUENODEPTR *, int *);
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, char, int *);
void instructions(void);

int main(){
    int elements = 0;
    QUEUENODEPTR headPtr = NULL, tailPtr = NULL;
    int choice;
    char item;

    instructions();
    printf("?");
    scanf("%d",&choice);

    while (choice != 3){
        switch (choice){
        case 1:
            printf("Enter a character: ");
            scanf("\n%c",&item);
            enqueue(&headPtr, &tailPtr, item, &elements);
            printQueue(headPtr, &elements);
            break;
        
        case 2:
            if (!isEmpty(headPtr)){
                item = dequeue(&headPtr, &tailPtr, &elements);
                printf("%c has been dequeued.\n",item);
            }
            printQueue(headPtr, &elements);
            break;
        
        default:
            printf("Invalid choice.\n\n");
            instructions();
            break;
        }
        printf("?");
        scanf("%d", &choice);
    }
    printf("End of run.\n");
    return 0;
}

void instructions(void){
    printf("Enter your choice:\n"
    "1 to add an item to the queue\n"
    "2 to remove an item from the queue\n"
    "3 to end\n");
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, char value, int *elementsPtr){
    QUEUENODEPTR newPtr;
    newPtr = malloc(sizeof(QUEUENODE));

    if (newPtr != NULL){
        newPtr->data = value;

        if (isEmpty(*headPtr)){
            *headPtr = newPtr;
            newPtr->nextPtr = NULL;
        }else{
            newPtr->nextPtr = *headPtr;
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
        (*elementsPtr)++;
    }
    else
        printf("%c is not inserted. No memory available.\n", value);
}

char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, int *elementsPtr){
    char value;
    QUEUENODEPTR tempPtr;
    value = (*headPtr)->data;
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

int isEmpty(QUEUENODEPTR headPtr){
    return headPtr == NULL;
}

void printQueue(QUEUENODEPTR currentPtr, int *elementsPtr){
    int i;
    if (currentPtr == NULL)
        printf("Queue is empty.\n\n");
    else{
        printf("The queue is:\n");
        for (i = 0; i < *elementsPtr; i++){
            printf("%c-->",currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}