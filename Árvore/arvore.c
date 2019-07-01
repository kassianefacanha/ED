#include "arvore_binaria.h"

arvore_binaria createChildren(int valor, arvore_binaria *sae, arvore_binaria *sad){
    arvore_binaria* bt = (arvore_binaria*)malloc(sizeof(arvore_binaria));
    bt -> valor = valor;
    bt -> esq = sae;
    bt -> dir = sad;
    return bt;
}
arvore_binaria create(int valor){
    return createChildren(valor, NULL, NULL);
    }
void destory(arvore_binaria *bt){
    if (br ==NULL) return;
     destory( bt -> esq);
     destory( bt -> dir);
     free(bt);
}
bool empty(arvore_binaria *bt){
    return (bt == NULL);
}
int height(arvore_binaria *bt){}
int size(arvore_binaria *bt){
    if(empty(bt)) return 0;
    return 1+size(bt -> esq)+size(bt -> dir);
}
int sheets(arvore_binaria *bt){}
bool find(arvore_binaria *bt){}
int level(arvore_binaria *bt){}
void printPreOrder(arvore_binaria *bt){}
void printPosOrder(arvore_binaria *bt){}
void printInOrder(arvore_binaria *bt){}
void printInLevel(arvore_binaria *bt){}
