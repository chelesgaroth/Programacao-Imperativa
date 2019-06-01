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

// 9             ------------- FAZEEEEEEEEEEEEER ---------------------

LInt parteAmeio (LInt *l){
	int meio = length(*l) / 2;
	int i;
	LInt new = malloc(sizeof(struct lligada));
	new->valor=(*l)->valor;
	new->prox=NULL;
	Lint list = new->prox;
	for(i=1;i< meio;i++){
		while((*l)!=NULL){
			list->valor=(*l)->valor;
			list->prox=NULL;
			*l=(*l)->prox;
			list=list->prox;
		}
	}
	return new;
}

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


typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

// 28

int altura (ABin a){
	int he,hd;
	if(a==NULL) return 0;
	else{
		he =altura(a->esq);
		hd=altura(a->dir);
		if(he<hd) return hd+1;
		else return he+1;
	}
}

// 29

ABin cloneAB (ABin a){
	if(a == NULL) return NULL;
	ABin new = malloc(sizeof(struct nodo));
	new->valor = a->valor;
	new ->esq= cloneAB(a->esq);
	new ->dir= cloneAB(a->dir);
	return new;
}

// 30

void mirror (ABin *a){
	if((*a)!=NULL){
		ABin temp= (*a)->esq;
		(*a)->esq=(*a)->dir;
		(*a)->dir=temp;
		mirror(&((*a)->esq));  // queremos o endereço, caso contrario iria ficar simplesmente ABin a e não ABin *a
		mirror(&((*a)->dir));
	}
}

// 31 

void inorder (ABin a, LInt *l){  //começamos por ver o que está no lado esquerdo pq tem os numeros mais pequenos
	if(a==NULL) (*l)=NULL;
	else{
		LInt new=malloc(sizeof(struct lligada));
		if(a->esq!=NULL) inorder(a->esq,l);
		new->valor=a->valor;
		new->prox=NULL;
		if((*l)==NULL) (*l)=new;
		else{
			while((*l)->prox!=NULL) l=&((*l)->prox);
			(*l)->prox=new;
		}
		if(a->dir!=NULL) inorder(a->dir,l);
	} // agora vemos os numeros do lado direito
}

// 32   

void preorderaux (ABin a, LInt *l){
	if (a != NULL){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=a->valor;
		new->prox=NULL;
		if((*l)==NULL) (*l)=new;
		else{
			while((*l)->prox!=NULL){
				l=&((*l)->prox);
			}
			(*l)->prox=new;
		}
		preorderaux(a->esq,l);
		preorderaux(a->dir,l);
	}
}
void preorder (ABin a, LInt *l){
	*l=NULL;
	preorderaux(a,l);
}


// 33   

void posorderaux (ABin a , LInt *l){
	if(a != NULL) {
		posorderaux(a->esq,l);
        posorderaux(a->dir,l);
        LInt new=malloc(sizeof(struct lligada));
		new->valor=a->valor;
		new->prox=NULL;
		if((*l)==NULL) (*l)=new;
		else{
			while((*l)->prox!=NULL){
				l=&((*l)->prox);
			}
			(*l)->prox=new;
		}
    }
}
void posorder (ABin a, LInt *l){
	*l=NULL;
	posorderaux(a,l);
}

// 34

int depth (ABin a, int x){
	int esq,dir;
	if(a==NULL) return -1;
	else {
		if(a->valor==x)return 1;
		esq=depth(a->esq,x);
		dir=depth(a->dir,x);
	}
	if(esq>0 && dir>0){
	    if(esq>dir) return dir+1;
	    else return esq+1;
	}
	else if(esq<0 && dir>0) return dir+1;
	else if(dir<0 && esq>0) return esq+1;
}

// 35

int freeAB (ABin a){
	int n=0;
	if (a==NULL) return n;
	else{
		free(a);
		n = 1+ freeAB(a->esq) + freeAB(a->dir);
	}
	return n;
}

// 36 

int pruneAB (ABin *a, int l){
	int n;
	if((*a)==NULL) return 0;
	if (l==0) {
		n = 1 + pruneAB(&((*a)->esq),l) + pruneAB(&((*a)->dir),l);
        free(*a);
        (*a) = NULL;
	}
	else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);
	return n;
}

// 37  

int iguaisAB (ABin a, ABin b){
	if (a==NULL && b != NULL) return 0;
	else if (a!= NULL && b==NULL) return 0;
	else if (a==NULL && b==NULL) return 1;
	else {
		if (a->valor==b->valor){
			return 1* iguaisAB(a->esq,b->esq) * iguaisAB(a->dir,b->dir);
		}
		else return 0;
	}
}

// 38

LInt nivelL (ABin a, int n){
	if(a ==NULL) return NULL;
	if(n==1){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=a->valor;
		new->prox=NULL;
		return new;
	}
	else {
		LInt l1,l2;
		l1=nivelL(a->esq,n-1);
		l2=nivelL(a->dir,n-1);
		if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		else{
			LInt temp=l1;
			while(temp->prox !=  NULL) temp=temp->prox;
			temp->prox=l2;
			return l1; 
		}
	}
}

// 39

int nivelV (ABin a, int n, int v[]){
	int i=0;
	if(a==NULL) return 0;
	if(n==1){
		v[i]=a->valor;
		return i+1;
	}
	else {
		int e= nivelV(a->esq,n-1,v);
		int d= nivelV(a->dir,n-1,v+e);
		return e+d;
	}
}

// 40 

int dumpAbin (ABin a, int v[], int N){
	if(a==NULL) return 0;
	if(N==0) return 0;
	else{
		int e,d;
		e= dumpAbin(a->esq,v,N-1);
		v[e]=a->valor;
		return e +1 + dumpAbin( a->dir , v+e+1 , N-(e+1) );
	}
}  // e+1 é a nova posicao a ocupar no vetor v

// 41 

ABin somasAcA (ABin a){
	if(a==NULL) return NULL;
	else{
		ABin new=malloc(sizeof(struct nodo));
		new->esq=somasAcA(a->esq);
		new->dir=somasAcA(a->dir);
		if(a->dir!=NULL && a->esq !=NULL){
			new->valor= a->valor + (new->dir)->valor + (new->esq)->valor;
		}
		else if (a->dir!=NULL && a->esq ==NULL){
			new->valor= a->valor + (new->dir)->valor;
		}
		else if (a->dir==NULL && a->esq !=NULL){
			new->valor= a->valor + (new->esq)->valor;
		}
		else {
			new->valor=a->valor;
		}
		return new;
	}
}

// 42 

int contaFolhas (ABin a){
	if(a==NULL) return 0;
	else{
		int e=contaFolhas(a->esq);
		int d=contaFolhas(a->dir);
		if(a->esq==NULL && a->dir==NULL){
			return 1 + e + d;
		}
		else return 0 + e + d;
	}
}

// 43 

ABin cloneMirror (ABin a){
	if(a==NULL) return NULL;
	else{
		ABin new=malloc(sizeof(struct nodo));
		new->valor=a->valor;
		new->dir=cloneMirror(a->esq);
		new->esq=cloneMirror(a->dir);
		return new;
	}
}

// 44

int addOrd (ABin *a, int x){
	if((*a)==NULL){
		ABin new=malloc(sizeof(struct nodo));
		new->valor=x;
		new->esq=new->dir=NULL;
		(*a)=new;
		return 0;
	}
	if((*a)->valor ==x) return 1;
	if((*a)->valor > x) return addOrd(&((*a)->esq),x);
	else return addOrd(&((*a)->dir),x);
}

// 45

int lookupAB (ABin a, int x){
	while(a!=NULL){
		if(x==a->valor) return 1;
		else if(x < a->valor) a=a->esq;
		else a=a->dir;
	}
	return 0;
}

// 46 

int depthOrd2 (ABin root, int x, int depth){
	if (root == NULL) return -1;
	if (x < root->valor) return depthOrd2(root->esq, x, depth + 1); 
	else if (x > root->valor) return depthOrd2(root->dir, x, depth + 1); 
	else return depth; 
} 

int depthOrd (ABin root, int x) {

	return depthOrd2(root, x, 1);
}

// 47 

int maiorAB (ABin a){
	int maior=a->valor;
	a=a->dir;
	while(a!=NULL){
		if(a->valor > maior)maior= a->valor;
		a=a->dir;
	}
	return maior;
}

// 48

void removeMaiorA (ABin *a){
	if((*a)->dir!=NULL){
		ABin temp=(*a);
		free(*a);
		if(temp->esq != NULL) (*a)=temp->esq;
		else (*a)=NULL;
	}
	else removeMaiorA(&((*a)->dir));
}

// 49 

int quantosMaiores (ABin a, int x){
	if(a == NULL) return 0;
	if(a->valor <= x) return quantosMaiores(a->dir,x);
	else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

// 50 

void listToBTree (LInt l, ABin *a){
	ABin new= malloc(sizeof(struct nodo));
	int meio = length(l)/2;
	LInt temp = l, prev =  NULL;
	int i;
	for(i=0; i < meio; i++){
		prev = temp;
		temp = temp ->prox;
	}
	new->valor= temp->valor;
	new->esq = new->dir = NULL;
	if(prev != NULL) prev->prox = NULL;

	if(l != NULL) listToBTree(l,&(new->esq));
	if(temp->prox != NULL) listToBTree(temp->prox,&(new->dir));
	(*a) = new;
}

// 51 

int deProcura (ABin a){
	if(a==NULL) return 1;

}
