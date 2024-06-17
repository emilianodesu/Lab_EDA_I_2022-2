#include "sll.h"

static Node *newNode(int val){
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    if (p != NULL){
        p->next = NULL;
        p->info = val;
    }

    return p;
}

SLL *SLL_New(){
    SLL *p;
    p = (SLL *)malloc(sizeof(SLL));
    if (p != NULL){
        p->head = NULL;
        p->tail = NULL;
    }

    return p;
}
void SLL_Delete(SLL *this){
    assert(this);
    while (this->head != this->tail){
        Node *temp = this->head->next;
        free(this->head);
        this->head = temp;
    }
    free(this->tail);
    free(this);
}

bool SLL_InsertFront(SLL *this, int val){
    assert(this);
    Node *p = newNode(val);
    if (this->head == NULL){
        this->head = p;
        this->tail = p;
    }else{
        Node *temp = this->head;
        this->head = p;
        this->head->next = temp;
    }

    return true;
}
int SLL_RemoveFront(SLL *this){
    assert(this);
    assert(this->head != NULL);
    Node *p = this->head->next;
    int a = this->head->info;
    free(this->head);
    this->head = p;

    return a;
}

int SLL_RemoveBack(SLL *this){
    assert(this);
    if (this->tail == NULL){
        printf("Vacía.\n");
        return -1;
    }
    Node *aux = this->head;
    while (aux->next != this->tail){
        aux = aux->next;
    }

    int a = this->tail->info;
    free(this->tail);
    this->tail = aux;
    this->tail->next = NULL;

    return a;
}
bool SLL_FindIf(SLL *this, int val){
    assert(this);
    Node *aux = this->head;
    while (aux->info != val){
        aux = aux->next;
        if (aux == NULL){
            printf("No está el dato.\n");
            return false;
        }
    }
    printf("El valor si está.\n");

    return true;
}

bool SLL_IsEmpty(SLL *this){
    assert(this);
    return this->head == NULL && this->tail == NULL;
}

void SLL_Purge(SLL *this){
    assert(this);
    while (this->head != this->tail){
        Node *temp = this->head->next;
        free(this->head);
        this->head = temp;
    }
    free(this->tail);
    this->head = NULL;
    this->tail = NULL;
}