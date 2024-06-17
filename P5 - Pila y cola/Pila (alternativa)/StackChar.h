#ifndef  STACKCHAR_INC
#define  STACKCHAR_INC

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bool.h"
// para usar true y false


typedef struct{
	char* stack;

	size_t top;
	size_t max;
} StackChar;


/*--------------------------------------------------------------------------*/
/**
 * @brief Crea a la pila.
 * Ambos, el objeto pila como su arreglo subyacente, se crean en el heap.
 *
 * @param max El número máximo de elementos en la pila
 *
 * @return Un objeto pila
 */
StackChar* StackChar_New (size_t max);

/*--------------------------------------------------------------------------*/
/**
 * @brief Inserta un elemento en la parte superior de la pila
 *
 * @param this Referencia al objeto de trabajo
 * @param x El valor a insertar
 *
 * @pre La pila existe
 * @pre La pila no está llena
 */
void StackChar_Push (StackChar* this, char x);


/*--------------------------------------------------------------------------*/
/**
 * @brief Extrae el elemento en la parte superior de la pila
 *
 * @param this Referencia al objeto de trabajo
 *
 * @return El elemento en la parte superior de la pila
 *
 * @pre La pila existe
 * @pre La pila no está vacía
 */
char StackChar_Pop (StackChar* this);

bool StackChar_IsEmpty (StackChar* this);
bool StackChar_IsFull (StackChar* this);
char StackChar_Peek (StackChar* this);




/*--------------------------------------------------------------------------*/
/**
 * @brief Destruye a un objeto pila creado con la función \see StackChar_New()
 *
 * @param this Referencia al objeto de trabajo
 *
 * @pre El objeto pila existe.
 */
void StackChar_Delete (StackChar* this);


#endif   /* ----- #ifndef STACKCHAR_INC  ----- */
