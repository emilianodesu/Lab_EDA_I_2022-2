#include "StackChar.h"

StackChar* StackChar_New (size_t max){
    StackChar *p=(StackChar*)calloc(1,sizeof(StackChar));
    if(p!=NULL){
        p->stack=(char*)calloc(max,sizeof(char));
        if(p->stack==NULL){
            free(p);
            return NULL;
        }else{
            p->top=0;
            p->max=max;
        }
        
    }

    return p;
}

void StackChar_Push (StackChar* this, char x){
    assert(this);
    if(this->top==this->max){
        assert(false);
    }
    this->stack[this->top]=x;
    ++this->top;
}

char StackChar_Pop (StackChar* this){
    assert(this);
    if(this->top==0){
        assert(false);
    }
    --this->top;
    char y=this->stack[this->top];

    return y;
}

bool StackChar_IsEmpty (StackChar* this){
    assert(this);

    return this->top==0;
}

bool StackChar_IsFull (StackChar* this){
    assert(this);

    return this->top==this->max;
}

char StackChar_Peek (StackChar* this){
    assert(this);
    if(this->top==0){
        assert(false);
    }

    return this->stack[this->top-1];
}

void StackChar_Delete (StackChar* this){
    assert(this);
    assert(this->stack);
    
    free(this->stack);
    free(this);
    
    this=NULL;
}