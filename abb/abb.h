#ifndef ABB_H
#define ABB_H

#define bool int
#define true 1
#define false 0
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct ab{
	int valor;
	int altura;
	int tamanho;
	int folhas;
	struct ab* esq;
	struct ab* dir;
} abb;

abb* createWithChildren(int valor,abb *sae,abb *sad);
abb* create(int valor);
abb* createEmpty();
void destroy(abb *bst);			
bool empty(abb *bst);
bool insert(abb **bst, int valor);
bool remover(abb **bst, int valor);
int height(abb *bst);
int size(abb *bst);
int sheets(abb *bst);
bool find(abb *bst, int valor); 
int level(abb *bst, int valor); 
void printPreOrder(abb *bst);
void printPosOrder(abb *bst);
void printInOrder(abb *bst);
void printInLevel(abb *bst);

#endif // ABB





