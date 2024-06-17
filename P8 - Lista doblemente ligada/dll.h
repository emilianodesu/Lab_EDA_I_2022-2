#ifndef DLL_INC
#define DLL_INC

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bool.h"

struct Node_Type{
    int info;
    struct Node_Type *next;
    struct Node_Type *prev;
};

typedef struct Node_Type Node;

typedef struct{
    Node *head;
    Node *tail;
} dll;

bool dll_IsEmpty(dll *this);
static Node *newNode(int val);
dll *dll_New();
void dll_Delete(dll *this);
bool dll_InsertBack(dll *this, int val);
bool dll_InsertFront(dll *this, int val);
int dll_RemoveFront(dll *this);
int dll_RemoveBack(dll *this);
bool dll_FindIf(dll *this, int val);

void dll_Purge(dll *this);
int menu();

#endif