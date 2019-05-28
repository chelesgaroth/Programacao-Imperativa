#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int, LInt);
int length (LInt l);

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

// 1

int length (LInt list) {
    int conta =0;
    while (list != NULL){
          conta++;
          list = list -> prox;
    }
    return conta;
}

// 2

void freeL (LInt l){
    LInt temp;
    while (l != NULL){
        temp = l;
        l= l -> prox;
        free(temp);
    }
}

// 3

void imprimeL (LInt l){
    while (l != NULL){
        printf ("%d",l-> valor);
        l=l->prox;
    }
}

// 4 

LInt reverseL (LInt l){
    LInt prev= NULL;
    LInt next;
    while (l != NULL){
        next=l->prox;
        l->prox=prev;
        prev=l;
        l=next;
    }
    return prev;
}
     
        
