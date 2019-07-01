#include "arvore_binaria.h"


arvore_binaria* createWithChildren(int valor, arvore_binaria *sae, arvore_binaria *sad){
	arvore_binaria* bt = (arvore_binaria*) malloc(sizeof(arvore_binaria));
	bt->valor = valor;
	bt->esq = sae;
	bt->dir = sad;
	return bt;
}

arvore_binaria* create(int valor){
	return createWithChildren(valor, NULL, NULL);
}

void destroy(arvore_binaria *bt){
	if(bt==NULL) return;
	destroy(bt->esq);
	destroy(bt->dir);
	free(bt);
}
			
bool empty(arvore_binaria *bt){
	return (bt==NULL);
}

int height(arvore_binaria *bt){
	if(empty(bt)) return -1;
	int altEsq = height(bt->esq);
	int altDir = height(bt->dir);
	return 1+(altEsq > altDir ? altEsq : altDir);
}

int size(arvore_binaria *bt){
	if(empty(bt)) return 0;
	return 1+size(bt->esq)+size(bt->dir);
}

int sheets(arvore_binaria *bt){
	if(empty(bt)) return 0;
	if(size(bt)==1) return 1;
	return sheets(bt->esq)+sheets(bt->dir);
}

bool find(arvore_binaria *bt, int valor){
	if(empty(bt)) return false;
	if(bt->valor == valor) return true;
	return find(bt->esq, valor) || find(bt->dir, valor);
}
 
int level(arvore_binaria *bt, int valor){
	/*if(!find(bt, valor)) return -1;
	if(bt->valor==valor) return 0;
	int resEsq = level(bt->esq, valor);
	int resDir = level(bt->dir, valor);
	return 1+(resEsq > resDir ? resEsq : resDir);*/
	if(empty(bt)) return -1;
	if(bt->valor==valor) return 0;
	int resEsq = level(bt->esq, valor);
	if(resEsq > -1) return 1+resEsq;
	int resDir = level(bt->dir, valor);
	if(resDir > -1) return 1+resDir;
	return -1;
}
 
void printPreOrder(arvore_binaria *bt){
	if(empty(bt)) return;
	printf("%d ", bt->valor);
	printPreOrder(bt->esq);
	printPreOrder(bt->dir);
}

void printPosOrder(arvore_binaria *bt){
	if(empty(bt)) return;
	printPosOrder(bt->esq);
	printPosOrder(bt->dir);
	printf("%d ", bt->valor);
}

void printInOrder(arvore_binaria *bt){
	if(empty(bt)) return;
	printInOrder(bt->esq);
	printf("%d ", bt->valor);
	printInOrder(bt->dir);
}

void printInLevel(arvore_binaria *bt){
	fila f = createFila();
	enqueue(&f, (void*) bt);
	while(!emptyFila(&f)){
		arvore_binaria *aux = 
			(arvore_binaria*) dequeue(&f);
		if(aux==NULL) continue;
		enqueue(&f, (void*) aux->esq);
		enqueue(&f, (void*) aux->dir);
		printf("%d ", aux->valor);
	}
	destroyFila(&f);
}






