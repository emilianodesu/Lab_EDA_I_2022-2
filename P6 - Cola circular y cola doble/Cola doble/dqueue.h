#ifndef  DQUEUE_INC
#define  DQUEUE_INC

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bool.h"

typedef int Item;

typedef struct{
	Item* queue;
	size_t head;
	size_t tail;
	size_t max;
} DQueue;

DQueue* DQueue_New( size_t n );
void DQueue_Delete( DQueue* this );
void DQueue_Insert( DQueue* this, Item x );
int DQueue_Remove( DQueue* this );
int DQueue_Peek( DQueue* this );

void DQueue_InsertBack( DQueue* this, Item x );
int DQueue_RemoveBack( DQueue* this );
int DQueue_PeekBack( DQueue* this );

bool DQueue_IsFull( DQueue* this );
bool DQueue_IsEmpty( DQueue* this );
void DQueue_Clear( DQueue* this );
void DQueue_ShiftLeft( DQueue* this );


#endif