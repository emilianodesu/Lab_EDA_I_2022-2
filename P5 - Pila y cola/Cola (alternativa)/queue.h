#ifndef QUEUE_INT
#define QUEUE_INT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bool.h"

typedef struct{
	int *queue;

	size_t head;
	size_t tail;
	size_t max;
} QueueInt;

QueueInt *QueueInt_New(int max);
void QueueInt_Shift(QueueInt *this);
void QueueInt_Insert(QueueInt *this, int x);
int QueueInt_Remove(QueueInt *this);
int QueueInt_Peek(QueueInt *this);
bool QueueInt_IsEmpty(QueueInt *this);
bool QueueInt_IsFull(QueueInt *this);
void QueueInt_Delete(QueueInt *this);
void QueueInt_Shift(QueueInt *this);

#endif