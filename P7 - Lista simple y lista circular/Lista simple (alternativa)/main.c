#include <stdio.h>
#include "sll.h"

int main(void){
	SLL *lista = SLL_New();

	// inserte los valores 6, 5, 4 en la parte frontal de la lista
	SLL_InsertFront(lista, 4);
	SLL_InsertFront(lista, 5);
	SLL_InsertFront(lista, 6);

	// verifique que el valor 4 estÃ© en la lista, y avise al usuario
	if (SLL_FindIf(lista, 4) == true){
		printf("El valor 4 SI esta en la lista\n");
	}else{
		printf("El valor 4 NO esta en la lista\n");
	}

	// verifique que el valor 9 no estÃ© en la lista, y avise al usuario
	printf("El valor 9 ");
	SLL_FindIf(lista, 9) ? printf("SI ") : printf("NO ");
	printf("esta en la lista\n");

	// extraiga todos los elementos de la lista
	while (SLL_IsEmpty(lista) == false){
		printf("%d\n", SLL_RemoveFront(lista));
	}

	SLL_Delete(lista);

	return 0;
}
