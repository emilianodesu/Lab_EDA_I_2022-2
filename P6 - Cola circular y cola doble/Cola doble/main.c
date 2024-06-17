#include <stdio.h>
#include "dqueue.h"

int main(void)
{

	size_t max = 10;
	DQueue *p = DQueue_New(max);

	DQueue_Insert(p, 1);
	DQueue_Insert(p, 2);
	DQueue_Insert(p, 3);
	DQueue_Insert(p, 4);

	printf("%d \n", DQueue_Remove(p));
	printf("%d \n", DQueue_Peek(p));
	DQueue_InsertBack(p, 25);

	printf("%d \n", DQueue_Remove(p));
	DQueue_ShiftLeft(p);
	printf("%d \n", DQueue_Remove(p));

	if (DQueue_IsFull(p) == true)
		printf("La cola está llena\n");
	else
		printf("La cola no está llena\n");

	DQueue_Delete(p);
	return 0;
}
