#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#define bool int
#define true 1
#define false 0
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct ab{
	int valor;
	struct ab* esq;
	struct ab* dir;
} arvore_binaria;

arvore_binaria* createWithChildren(int valor, arvore_binaria *sae, arvore_binaria *sad);
arvore_binaria* create(int valor);
void destroy(arvore_binaria *bt);			
bool empty(arvore_binaria *bt);
int height(arvore_binaria *bt);
int size(arvore_binaria *bt);
int sheets(arvore_binaria *bt);
bool find(arvore_binaria *bt, int valor); 
int level(arvore_binaria *bt, int valor); 
void printPreOrder(arvore_binaria *bt);
void printPosOrder(arvore_binaria *bt);
void printInOrder(arvore_binaria *bt);
void printInLevel(arvore_binaria *bt);

#endif





