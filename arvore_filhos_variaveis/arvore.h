#ifndef ARVORE_H
#define ARVORE_H

#define bool int
#define true 1
#define false 0
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct tree{
	int valor;
	struct tree* filho;
	struct tree* irmao;
} arvore;

arvore* createWithChildren(int valor, arvore* filhos[], int n);
arvore* create(int valor);
void destroy(arvore *t);			
bool empty(arvore *t);
int height(arvore *t);
int size(arvore *t);
int sheets(arvore *t);
bool find(arvore *t, int valor); 
int level(arvore *t, int valor); 
void printPreOrder(arvore *t);
void printPosOrder(arvore *t);
void printInLevel(arvore *t);

#endif





