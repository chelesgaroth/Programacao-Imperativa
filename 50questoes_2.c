#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//        ---------------  LISTAS LIGADAS   -----------------

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


// 8

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
	if (l==NULL){
		*mx=NULL;
		*Mx=NULL;
	}
	else{
		if (l->valor < x){
			*mx = l;
			l=l->prox;
		}
		else if (l->valor > x) {
			*Mx =l;
			l=l->prox;
		}
		else{
			*mx=NULL;
			*Mx=NULL;
			l=l->prox;
		}
		while(l!=NULL){
			if (l->valor < x){
				(*mx)->prox= l;
				mx=&((*mx)->prox);
				l=l->prox;
			}
			else {
				(*Mx)->prox= l;
				Mx=&((*Mx)->prox);
				l=l->prox;
			} 
		}
		(*mx)->prox=NULL;
		(*Mx)->prox=NULL;
	}
}

// 9

// 10

int removeAll (LInt *l, int x){
    int conta=0;
    while((*l) != NULL){
        if((*l)->valor ==x){
            *l=(*l)->prox;
            conta++;
        }
        else{
            l=&((*l)->prox);
        }
    }
    return conta;
}

// 11

int removeDups (LInt *l){
	int conta=0;
	LInt current=*l;
	LInt prev=current;
	LInt move;
	int x=(*l)->valor;
	while(current != NULL){
		x=current->valor;
		prev=current;
		move=current->prox;
		while(move != NULL){
			if(move->valor == x){
			    conta++;
			    prev -> prox= move ->prox;
			    move=move->prox;
			}
			else{
			prev=move;
			move=move->prox;
			}
		}
		current=current->prox;
	}
	return conta;
}

// 12

int removeMaiorL (LInt *l){
	LInt current = (*l)->prox;
    LInt prev = (*l);
    int maior = (*l)->valor;
    LInt maiorL;
    LInt maxPrev;
	while (current != NULL){
		if (current->valor > maior){
			maior = current->valor;
			maiorL=current;
			maxPrev=prev;
		}
		prev=current;
		current = current->prox;
	}
	if(maior == (*l)->valor)
        (*l) = (*l)->prox;
    else{
	    maxPrev->prox = maiorL->prox;
    }
	return maior;
}

// 13

void init (LInt *l){
 	while ((*l)->prox != NULL){
 		l=&((*l)->prox);
 	}
 	free(*l);
 	*l=NULL;
}

// 14

void appendL (LInt *l, int x){
	LInt new = malloc(sizeof(struct lligada));
	new->valor=x;
	new->prox = NULL;
	if((*l) == NULL){
	    (*l) = new;
	}
    else{
		while ((*l)->prox != NULL){
			l=&((*l)->prox);
 		}
		(*l)->prox=new;
	}
}

// 15

void concatL (LInt *a, LInt b){
	if ((*a)==NULL){
		*a=b;
	}
	else{
		while ((*a)->prox != NULL){
			a=&((*a)->prox);
 		}
		(*a)->prox=b;
	}
}

// 16

LInt cloneL (LInt l){
	LInt list=NULL,inicio=NULL;
	while(l!=NULL){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=l->valor;
		new->prox=NULL;
		if(inicio==NULL) list=inicio=new;
		else{
			list=list->prox=new;
		}
		l=l->prox; 
	}
	return inicio;
}

// 17

LInt cloneRev (LInt l){
	LInt prev=NULL;
	while(l!=NULL){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=l->valor;
		new->prox=prev;
		prev=new;
		l=l->prox; 
	}
	return prev;
}

// 18

int maximo (LInt l){
 	int maior=l->valor;
 	l=l->prox;
 	while(l != NULL){
 		if(l->valor > maior){
 			maior=l->valor;
 		}
 		l=l->prox;
 	}
 	return maior;
}

// 19

int take (int n, LInt *l) {
	int length=0;
	while( ((*l) != NULL) && (length<=n)){
		length++;
		if(length<=n) l=&((*l)->prox);	//porque assim que length>n,nao andamos um nodo para a frente e alteramos já esse nodo;
	}
	if (length>n){
		free(*l);
		(*l)=NULL;
		return n;
	}
	else return length;
}

// 20

int drop (int n, LInt *l){
	int i=0;
	LInt temp; //criar a temporaria por causa do free
	while( ((*l) != NULL) && i<n){
		temp=*l;
		i++;
		*l=(*l)->prox;
		free(temp);
    }
    return i;
}

// 21 

LInt NForward (LInt l, int N){
    int i;
	for(i=0;i<N;i++){
		l=l->prox;
	}
	return l;
} 

// 22 

int listToArray (LInt l, int v[], int N){
	int i=0;
	while(l != NULL && i<N){
		v[i]= l->valor;
		l=l->prox;
		i++;
	}
	return i;
}

// 23

LInt arrayToList (int v[], int N){
	LInt inicio=NULL;
	LInt list=NULL;
	int i;
	for(i=0;i<N;i++){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=v[i];
		new->prox=NULL;
		if(inicio==NULL)inicio=list=new;
		else list=list->prox=new; 
	}
	return inicio;
}

// 24

LInt somasAcL (LInt l){
	LInt inicio=NULL;
	LInt list=NULL;
	int soma=0;
	while(l!=NULL){
		LInt new=malloc(sizeof(struct lligada));
		soma=soma+l->valor;
		new->valor=soma;
		new->prox=NULL;
		if(inicio==NULL)inicio=list=new;
		else list=list->prox=new; 
		l=l->prox;
	}
	return inicio;
}

// 25

void remreps (LInt l){ //podemos fazer desta forma porque é uma lista ordenada
	LInt temp;
	if(l != NULL) {
        while(l->prox != NULL) {
            if((l->prox)->valor == l->valor) {
                temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

// 26 

LInt rotateL (LInt l){
	if(l==NULL || l->prox==NULL) return l;
	LInt first=l;
	LInt list=l->prox;
	while(l->prox != NULL){
		l=l->prox;
	}
	first->prox=NULL;
	l->prox=first;
	return list;
}

// 27

LInt parte (LInt l) {
    LInt inicio = NULL, list = NULL;
    while(l!=NULL && l->prox!=NULL) {
        if(inicio==NULL) inicio = list = l->prox;
        else list = list->prox = l->prox;
        l = l->prox = l->prox->prox;
        list->prox = NULL;
    }
    return inicio;
}

//       ------------- 	ÁRVORES BINÁRIAS  --------------

// 28

