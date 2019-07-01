#include "abb.h"

void organize(abb* bst){
	if(empty(bst)) return;
	if(bst->esq==NULL && bst->dir==NULL){
		bst->altura = 0;
		bst->tamanho = bst->folhas = 1;
	} else {
		organize(bst->dir);
		organize(bst->esq);
		bst->altura = 1 + (height(bst->esq)>height(bst->dir) ? height(bst->esq) : height(bst->dir));
		bst->tamanho = 1 + size(bst->esq) + size(bst->dir);
		bst->folhas = (bst->esq==NULL && bst->dir==NULL ? 1 : sheets(bst->esq)+sheets(bst->dir));
	}
}

abb* createWithChildren(int valor,abb *sae,abb *sad){
	abb* bst = (abb*) malloc(sizeof(abb));
	bst->esq = sae;
	bst->dir = sad;
	bst->valor = valor;
	bst->altura = 1 + (height(sae)>height(sad) ? height(sae) : height(sad));
	bst->tamanho = 1 + size(sae) + size(sad);
	bst->folhas = (sae==NULL && sad==NULL ? 1 : sheets(sae)+sheets(sad));
	return bst;
}

abb* create(int valor){
	return createWithChildren(valor, NULL, NULL);
}

abb* createEmpty(){
	return NULL;
}

void destroy(abb *bst){
	if(empty(bst)) return;
	destroy(bst->esq);
	destroy(bst->dir);
	free(bst);
}

bool empty(abb *bst){
	return bst==NULL;
}

bool insert(abb **bst, int valor){
	if(empty(*bst)){
		*bst = create(valor);
		return true;
	} else {
		if((*bst)->valor == valor) return false;
		if((*bst)->valor < valor) {
			bool res = insert(&((*bst)->dir), valor);
			if(res){
				(*bst)->tamanho++;
				(*bst)->altura = 1 + (height((*bst)->esq)>height((*bst)->dir) ? height((*bst)->esq) : height((*bst)->dir));
				(*bst)->folhas = sheets((*bst)->esq)+sheets((*bst)->dir);
			}
			return res;
		} else {
			bool res = insert(&((*bst)->esq), valor);
			if(res){
				(*bst)->tamanho++;
				(*bst)->altura = 1 + (height((*bst)->esq)>height((*bst)->dir) ? height((*bst)->esq) : height((*bst)->dir));
				(*bst)->folhas = sheets((*bst)->esq)+sheets((*bst)->dir);
			}
			return res;
		}
	}
}

void swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}



void remocaoPorCopiaEsquerda(abb** p){
	// por copia a esquerda
	abb **pz = &(*p)->esq;
	abb *z = (*p)->esq;
	while(z->dir != NULL) {
		pz = &z->dir;
		z = z->dir;
	}
	swap(&z->valor, &(*p)->valor);
	remover(pz, z->valor);
}

void remocaoPorCopiaDireita(abb** p){
	// por copia a direita
	abb **pz = &(*p)->dir;
	abb *z = (*p)->dir;
	while(z->esq != NULL) {
		pz = &z->esq;
		z = z->esq;
	}
	swap(&z->valor, &(*p)->valor);
	remover(pz, z->valor);
}

void remocaoPorFusaoEsquerda(abb** p){
	// por fusão a esquerda
	abb* r = *p;
	abb *z = r->esq;
	while(z->dir != NULL) z = z->dir;
	*p = r->esq;
	z->dir = r->dir;
	free(r);
}

void remocaoPorFusaoDireita(abb **p){
	// por fusao a direita
	abb* r = *p;
	abb *z = r->dir;
	while(z->esq != NULL) z = z->esq;
	*p = r->dir;
	z->esq = r->esq;
	free(r);
}

bool remover(abb **bst, int valor){
	if(empty(*bst)) return false;
	abb **p = bst;
	abb *r = *bst;
	while(r != NULL && r->valor != valor) {
		p = (r->valor < valor ? &r->dir : &r->esq);
		r = (r->valor < valor ? r->dir : r->esq);
	}
	if(r==NULL) return false; // valor não encontrado
	if(r->esq==NULL || r->dir==NULL) { // já trata o caso de 1 ou 2 filhos de r
		*p = (r->esq==NULL ? r->dir : r->esq);
		free(r);
	} else { // se r tem 2 filhos 
		static int tipo_remocao = -1;
		tipo_remocao = (tipo_remocao+1)%4;
		switch(tipo_remocao){
			case 0: remocaoPorCopiaEsquerda(p); break;
			case 1: remocaoPorCopiaDireita(p); break;
			case 2: remocaoPorFusaoEsquerda(p); break;
			case 3: remocaoPorFusaoDireita(p); break;
		}
	}
	organize(*bst);
	return true;
}

int height(abb *bst){
	if(empty(bst)) return -1;
	return bst->altura;
}

int size(abb *bst){
	if(empty(bst)) return 0;
	return bst->tamanho;
}

int sheets(abb *bst){
	if(empty(bst)) return 0;
	return bst->folhas;
}

bool find(abb *bst, int valor){
	if(empty(bst)) return false;
	if(bst->valor == valor) return true;
	if(bst->valor < valor) 
		return find(bst->dir,valor);
	else 
		return find(bst->esq,valor);
}

int level(abb *bst, int valor){
	if(empty(bst)) return -1;
	if(bst->valor == valor) return 0;
	int res = 0;
	if(bst->valor < valor) 
		res = level(bst->dir,valor);
	else 
		res = level(bst->esq,valor);
	if(res > -1) res++;
	return res;
}

void printPreOrder(abb *bt){
	if(empty(bt)) return;
	printf("%d ", bt->valor);
	printPreOrder(bt->esq);
	printPreOrder(bt->dir);
}

void printPosOrder(abb *bt){
	if(empty(bt)) return;
	printPosOrder(bt->esq);
	printPosOrder(bt->dir);
	printf("%d ", bt->valor);
}

void printInOrder(abb *bt){
	if(empty(bt)) return;
	printInOrder(bt->esq);
	printf("%d ", bt->valor);
	printInOrder(bt->dir);
}

void printInLevel(abb *bt){
	fila f = createFila();
	enqueue(&f, (void*) bt);
	while(!emptyFila(&f)){
		abb *aux = 
			(abb*) dequeue(&f);
		if(aux==NULL) continue;
		enqueue(&f, (void*) aux->esq);
		enqueue(&f, (void*) aux->dir);
		printf("%d ", aux->valor);
	}
	destroyFila(&f);
}






