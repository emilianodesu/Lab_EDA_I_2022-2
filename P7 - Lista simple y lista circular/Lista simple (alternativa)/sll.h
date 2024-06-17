#ifndef SLL_INC
#define SLL_INC

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bool.h"

struct Node_Type
{
	int info;
	// datos

	struct Node_Type *next;
	// apuntador al siguiente nodo
};

typedef struct Node_Type Node;

typedef struct
{
	Node *head;
	// apuntador al primer nodo

	Node *tail;
	// apuntador al Ãºltimo nodo
} SLL;

static Node *newNode(int val);
SLL *SLL_New();
void SLL_Delete(SLL *this);
bool SLL_InsertFront(SLL *this, int val);
int SLL_RemoveFront(SLL *this);
int SLL_RemoveBack(SLL *this);
bool SLL_FindIf(SLL *this, int val);
bool SLL_IsEmpty(SLL *this);
void SLL_Purge(SLL *this);

#endif