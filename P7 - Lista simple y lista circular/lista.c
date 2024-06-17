#include <stdio.h>
#include <stdlib.h>

struct listNode{
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *, char);
char delete (LISTNODEPTR *, char);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void instructions(void);

int main(){
    LISTNODEPTR startPtr = NULL;
    int choice;
    char item;

    instructions();
    printf("? ");
    scanf("%d", &choice);

    while(choice != 3){
        switch (choice){
        case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item);
            printList(startPtr);
            break;
        case 2:
            if (!isEmpty(startPtr)){
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);

                if (delete (&startPtr, item)){
                    printf("%c deleted.\n", item);
                    printList(startPtr);
                }else
                    printf("The element doesn't exist.\n");
            }else
                printf("List is empty.\n\n");
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
            "1 to insert an element into the list.\n"
            "2 to delete an element from the list.\n"
            "3 to end.\n");
}

void insert(LISTNODEPTR *sPtr, char value){
    LISTNODEPTR newPtr, previousPtr, currentPtr;
    newPtr = malloc(sizeof(LISTNODE));

    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *sPtr;
        // printf("contenido newPtr %p \n", newPtr);
        // printf("contenido previousPtr %p \n", previousPtr);
        // printf("contenido currentPtr %p \n", currentPtr);
        // printf("contenido sPtr %p \n", *sPtr);

        while(currentPtr != NULL && value != currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
            // printf("contenido sPtr2 %p \n", *sPtr);
        }else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }else
        printf("%c not inserted. No memory available.\n", value);
}

char delete(LISTNODEPTR *sPtr, char value){
    LISTNODEPTR previousPtr, currentPtr, tempPtr;

    if(value == (*sPtr)->data){
        tempPtr == *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

int isEmpty(LISTNODEPTR sPtr){
    return sPtr == NULL;
}

void printList(LISTNODEPTR currentPtr){
    if (currentPtr == NULL)
        printf("List is empty. \n\n");
    else{
        while (currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}