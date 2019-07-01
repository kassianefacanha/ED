#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <limits.h>
#define bool int
#define true 1
#define false 0
#define INT_INVALIDO INT_MIN

typedef struct nodo {
	void* valor;
	struct nodo* prox;
} no;

typedef struct {
	no* ini;
	no* fim;
	int comprimento;	
} fila;

fila createFila();
bool enqueue(fila *f, void* x);
void* dequeue(fila *f);
void* begin(fila *f);
void* end(fila *f);
bool emptyFila(fila *f);
bool fullFila(fila *f);
int lengthFila(fila *f);
void destroyFila(fila *f);
#endif // FILA_H
