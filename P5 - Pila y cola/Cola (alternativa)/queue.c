#include "queue.h"

QueueInt *QueueInt_New(int max){
    QueueInt *p;
    p = (QueueInt *)malloc(sizeof(QueueInt));
    if (p == NULL){
        return p;
    }

    p->queue = (int *)malloc(max * sizeof(int));
    if (p->queue == NULL){
        free(p);
        return NULL;
    }

    p->max = max;
    p->head = 0;
    p->tail = 0;

    return p;
}

void QueueInt_Insert(QueueInt *this, int x){
    if (this->tail == this->max){
        printf("La cola esta llena.\n");
        assert(false);
    }
    this->queue[this->tail] = x;
    ++this->tail;
}

int QueueInt_Remove(QueueInt *this){
    if (this->tail == 0){
        printf("la cola esta vacia");
        return -1;
    }

    int temp = this->queue[this->head];
    ++this->head;
    return temp;
}

int QueueInt_Peek(QueueInt *this){
    return this->queue[this->head];
}

bool QueueInt_IsEmpty(QueueInt *this){
    return this->tail == 0;
}

bool QueueInt_IsFull(QueueInt *this){
    return this->tail == this->max && this->head == 0;
}

void QueueInt_Delete(QueueInt *this){
    if (this != NULL){
        if (this->queue != NULL){
            free(this->queue);
            free(this);
        }
    }
    this = NULL;
}

void QueueInt_Shift(QueueInt *this){
    assert(this);
    assert(this->queue);
    if (this->tail == this->max && this->head != 0){
        size_t elem = (this->tail) - (this->head);
        size_t temp[elem];
        for (size_t i = 0; i < elem; ++i){
            temp[i] = this->queue[this->head];
            ++this->head;
        }
        this->head = 0;
        this->tail = 0;
        for (size_t i = 0; i < elem; ++i){
            this->queue[this->tail] = temp[i];
            ++this->tail;
        }
    }
}

/*void QueueInt_Shift(QueueInt *this)
{
    if ((this->tail == 0) || (this->tail == this->max && this->head == 0))
        assert(false);

    for (size_t i = 0; i <= this->tail - this->head; i++)
    {
        this->queue[i] = this->queue[(this->head) + i];
    }
    this->tail = this->tail - this->head;
    this->head = 0;
}*/

/* void QueueInt_Shift (Cola *cola)
{
    int indice;
    for(indice=0;indice<=cola->max;indice++)
    {
        cola->arrCola[indice]=cola->arrCola[indice+1];
    }
    cola->h--;
    cola->t--;
}   Implementación diferente.*/
