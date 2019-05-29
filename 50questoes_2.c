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

// 5

void insertOrd (LInt *a, int x){
    LInt novo;
    novo=malloc(sizeof(struct lligada));
    novo->valor=x;

    while(((*a)!=NULL) && ((*a)->valor)<x){
        a=&((*a)->prox);
    }
    novo->prox=*a;
    *a=novo;
}

// 6

int removeOneOrd (LInt *l , int x){
    while ((*l!= NULL)&& ((*l)->valor != x)) {
		l=&((*l)->prox);
	}
	if (*l == NULL){
		return 1;
	}
	else{
		*l = (*l)-> prox;
		return 0;
	}	
}

// 7

void merge (LInt *r, LInt l1, LInt l2){
	if(l1 == NULL){
		*r=l2;
	}
	else if (l2==NULL){
		*r=l1;
	}
	else if ((l1 == NULL)&&(l2==NULL)){
		*r=NULL;
	}
	else{
		if(l1->valor < l2->valor){
			*r=l1;
			l1=l1->prox;
		}
		else{
			*r=l2;
			l2=l2->prox;
		}
		while((l1 != NULL)&&(l2 != NULL)){
			if(l1->valor < l2->valor){
				(*r)->prox=l1;
				r=&((*r)->prox);
				l1=l1->prox;
			}
			else{
				(*r)->prox=l2;
				r=&((*r)->prox);
				l2=l2->prox;
			}
		}
		if(l1==NULL){
			(*r)->prox=l2;
		}
		else {
			(*r)->prox=l1;
		}
	}
}

// 8                  ------      NAO ESTÁ CERTO , É NECESSÁRIO REVER     --------

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    
    if(l==NULL){
        *Mx=NULL;
        *mx=NULL;
    }
    else{
        if(l->valor < x){
            *mx=l;
            *Mx=NULL;
            l=l->prox;
        }
        else{
            *Mx=l;
            *mx=NULL;
            l=l->prox;
        }
        while (l != NULL){
            if(l->valor < x){
                (*mx)->prox= l;
                mx= &((*mx)->prox);
                l=l->prox;
            }
            else{
                (*Mx)->prox= l;
                Mx= &((*Mx)->prox);
                l=l->prox;
            }
        }
        (*mx)->prox=NULL;
        (*Mx)->prox=NULL;
    }
    
}
