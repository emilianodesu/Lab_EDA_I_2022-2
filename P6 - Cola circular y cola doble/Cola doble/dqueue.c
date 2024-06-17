#include "dqueue.h"

DQueue *DQueue_New(size_t n){
    DQueue *p = (DQueue *)malloc(sizeof(DQueue));
    if (p != NULL){
        p->queue = (Item *)malloc(sizeof(Item) * n);
        if (p->queue != NULL){
            p->max = n;
            p->head = 0;
            p->tail = 0;
        }
    }

    return p;
}

void DQueue_Delete(DQueue *this){
    if (this != NULL){
        free(this->queue);
        free(this);
        this = NULL;
    }
}

void DQueue_Insert(DQueue *this, Item x){
    assert(this);
    assert(!DQueue_IsFull(this));
    assert(!(this->tail == this->max));
    this->queue[this->tail] = x;
    ++this->tail;
}

Item DQueue_Remove(DQueue *this){
    assert(this);
    assert(!(DQueue_IsEmpty(this)));
    int x = this->queue[this->head];
    this->queue[this->head] = -1;
    ++this->head;
    return x;
}

Item DQueue_Peek(DQueue *this){
    assert(this);
    return this->queue[this->head];
}

void DQueue_InsertBack(DQueue *this, Item x){
    // Aquí iría DQueue_ShiftRight
    assert(this);
    if (this->head != 0){
        --this->head;
        this->queue[this->head] = x;
    }else{
        printf("No se puede insertar por head \n");
    }
}

int DQueue_RemoveBack(DQueue *this){
    assert(this);
    if (this->head == this->tail && this->tail == 0){
        printf("No hay datos.\n");
        return -1;
    }

    int x = this->queue[this->tail];
    this->queue[this->tail] = -1;
    --this->tail;

    return x;
}

int DQueue_PeekBack(DQueue *this){
    assert(this);
    assert(this->queue);
    return this->queue[this->tail];
}

bool DQueue_IsFull(DQueue *this){
    assert(this);
    return (this->head == 0 & this->tail == this->max);
}

bool DQueue_IsEmpty(DQueue *this){
    assert(this);
    return (this->head == this->tail && this->tail == 0);
}

void DQueue_Clear(DQueue *this){
    this->head = 0;
    this->tail = 0;
}

void DQueue_ShiftLeft(DQueue *this){
    assert(this);
    assert(!DQueue_IsFull(this));
    assert(!DQueue_IsEmpty(this));
    size_t j = 0;
    for (size_t i = this->head; i < this->tail; ++i){
        this->queue[j] = this->queue[i];
        ++j;
    }
    this->head = 0;
    this->tail = j;
}

/*void DQueue_ShiftRight( DQueue* this ){

}*/