#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
#define boll int
#define true 1
#define false 0
#include<stdlib.h>

typedef struct ab{
    int valor;
    struct ab* esquerda;
    struct ab* direita;

}arvore_binaria

arvore_binaria createChildren(int valor, arvore_binaria *sae, arvore_binaria *sad);
arvore_binaria create(int valor);
void destory(arvore_binaria *bt);
bool empty(arvore_binaria *bt);
int height(arvore_binaria *bt);
int size(arvore_binaria *bt);
int sheets(arvore_binaria *bt);
bool find(arvore_binaria *bt);
int level(arvore_binaria *bt);
void printPreOrder(arvore_binaria *bt);
void printPosOrder(arvore_binaria *bt);
void printInOrder(arvore_binaria *bt);
void printInLevel(arvore_binaria *bt);



#endif // ARVORE_BINARIA_H
