#include "fila.h"
// FUNÇÕES DO NÓ
no* createNo(void* x){
	no* n = (no*) malloc(sizeof(no));
	n->valor = x;
	n->prox = NULL;
	return n;
}

void destroyNo(no* n){
	if(n==NULL) return;
	destroyNo(n->prox);
	free(n);
}

// FUNÇÕES DA FILA
fila createFila(){
	fila f;
	f.comprimento = 0;
	f.ini = f.fim = NULL;
	return f;
}

bool enqueue(fila *f, void* x){
	no* novo = createNo(x);
	if(emptyFila(f)) f->ini = f->fim = novo;
	else {
		f->fim->prox = novo;
		f->fim = novo;
	}
	f->comprimento++;
	return true;
}

void* dequeue(fila *f){
	if(emptyFila(f)) return NULL;
	void* x = f->ini->valor;
	if(lengthFila(f) == 1) f->fim = NULL;
	no* aux = f->ini;
	f->ini = f->ini->prox;
	free(aux);
	f->comprimento--;
	return x;
}

void* begin(fila *f){
	if(emptyFila(f)) return NULL;
	return f->ini->valor;
}

void* end(fila *f){
	if(emptyFila(f)) return NULL;
	return f->fim->valor;
}

bool emptyFila(fila *f){
	return (f->comprimento==0);
}

bool fullFila(fila *f){
	return false;
}

int lengthFila(fila *f){
	return f->comprimento;
}

void destroyFila(fila *f){
	destroyNo(f->ini);
	f->ini = f->fim = NULL;
}
