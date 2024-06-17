#include "dll.h"

static Node *newNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    if (p != NULL){
        p->info = val;
        p->next = NULL;
        p->prev = NULL;
    }

    return p;
}

dll *dll_New(){
    dll *p = (dll *)malloc(sizeof(dll));
    if (p != NULL){
        p->head = NULL;
        p->tail = NULL;
    }

    return p;
}

bool dll_InsertBack(dll *this, int val){
    assert(this);
    Node *p = newNode(val);
    if (p != NULL){
        if (this->head == NULL){
            this->head = p;
            this->tail = p;
        }else{
            this->tail->next = p;
            p->prev = this->tail;
            this->tail = p;
        }
        return true;
    }

    return false;
}

bool dll_InsertFront(dll *this, int val){
    assert(this);
    Node *p = newNode(val);
    if (p != NULL){
        if (this->head == NULL){
            this->head = p;
            this->tail = p;
        }else{
            this->head->prev = p;
            p->next = this->head;
            this->head = p;
        }
        return true;
    }
    
return false;
}

int dll_RemoveFront(dll *this){
    assert(this);
    assert(!dll_IsEmpty(this));
    Node *aux = this->head->next;
    int a = this->head->info;
    free(this->head);
    this->head = aux;
    if (this->head == NULL)
        this->tail = NULL;
    return a;
}

int dll_RemoveBack(dll *this){
    assert(this);
    assert(!dll_IsEmpty(this));
    Node *aux = this->tail->prev;
    int a = this->tail->info;
    free(this->tail);
    this->tail = aux;
    if (this->tail == NULL)
        this->head = NULL;
    
    return a;
}

void dll_Delete(dll *this){
    assert(this);
    Node *aux;
    while (this->head->next != NULL){
        aux = this->head->next;
        free(this->head);
        this->head = aux;
    }
    free(this->tail);
    free(this);
}

bool dll_FindIf(dll *this, int val){
    assert(this);
    Node *aux = this->head;
    while (aux->info != val){
        aux = aux->next;
    }

    if (aux == NULL){
        return false;
    }

    return true;
}

bool dll_IsEmpty(dll *this){
    return this->head == NULL;
}

void dll_Purge(dll *this){
    assert(this);
    if (dll_IsEmpty(this) == true)
        return;
    Node *aux;
    while (this->head->next != NULL){
        aux = this->head->next;
        free(this->head);
        this->head = aux;
    }
    free(this->tail);
    this->head = NULL;
    this->tail = NULL;
}

int menu(){
    int opcion = 0;

    do{
        printf("\n"
                "1 -- Inserta un elemento en el extremo posterior de la lista\n"
                "2 -- Inserta un elemento en el extremo anterior de la lista\n"
                "3 -- Extrae el elemento del extremo posterior de la lista\n"
                "4 -- Extrae el elemento del extremo anterior de la lista\n"
                "5 -- Indica si un valor esta en la lista o no\n"
                "6 -- Indica si la lista esta vacia o no\n"
                "7 -- Purga la lista\n"
                "0 -- Terminar\n"
                "Su opcion> ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 7);
    printf("\n");

    return opcion;
}