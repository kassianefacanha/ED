#include "arvore.h"

arvore* createWithChildren(int valor, arvore* filhos[], int n){
	arvore* t = (arvore*) malloc(sizeof(arvore));
	t->valor = valor;
	t->irmao = NULL;
	if(n > 0){
		t->filho = filhos[0];
		int k;
		for(k=1;k<n;k++) filhos[k-1]->irmao = filhos[k];
	} else t->filho = NULL;
	return t;
}

arvore* create(int valor){
	return createWithChildren(valor, NULL, 0);
}

void destroy(arvore *t){
	if(t==NULL) return;
	destroy(t->filho);
	destroy(t->irmao);
	free(t);
}
			
bool empty(arvore *t){
	return t==NULL;
}

int height(arvore *t){
	if(empty(t)) return -1;
	int max = -1;
	arvore *aux = t->filho;
	while(aux != NULL){
		int altAux = height(aux);
		if(altAux > max) max = altAux;
		aux = aux->irmao;
	}
	return max+1;
}

int size(arvore *t){
	if(empty(t)) return 0;
	int soma = 0;
	arvore *aux = t->filho;
	while(aux != NULL){
		soma += size(aux);
		aux = aux->irmao;
	}
	return soma+1;
}

int sheets(arvore *t){
	if(empty(t)) return 0;
	if(size(t) == 1) return 1;
	int soma = 0;
	arvore *aux = t->filho;
	while(aux != NULL){
		soma += sheets(aux);
		aux = aux->irmao;
	}
	return soma;
}

bool find(arvore *t, int valor){
	if(empty(t)) return false;
	if(t->valor == valor) return true;
	arvore *aux = t->filho;
	while(aux != NULL){
		if(find(aux,valor)) return true;
		aux = aux->irmao;
	}
	return false;
}
 
int level(arvore *t, int valor){
	if(empty(t)) return -1;
	if(t->valor == valor) return 0;
	arvore *aux = t->filho;
	while(aux != NULL){
		int resAux = level(aux,valor);
		if(resAux > -1) return resAux + 1;
		aux = aux->irmao;
	}
	return -1;
}
 
void printPreOrder(arvore *t){
	if(empty(t)) return;
	printf("%d ", t->valor);
	arvore *aux = t->filho;
	while(aux != NULL){
		printPreOrder(aux);
		aux = aux->irmao;
	}
}

void printPosOrder(arvore *t){
	if(empty(t)) return;
	arvore *aux = t->filho;
	while(aux != NULL){
		printPosOrder(aux);
		aux = aux->irmao;
	}
	printf("%d ", t->valor);
}

void printInLevel(arvore *t){
	if(empty(t)) return;
	fila f = createFila();
	enqueue(&f, (void*) t);
	while(!emptyFila(&f)){
		arvore *no = (arvore*) dequeue(&f);
		if(no==NULL) continue;
		arvore *aux = no->filho;
		while(aux != NULL){
			enqueue(&f, (void*) aux);
			aux = aux->irmao;
		}
		printf("%d ", no->valor);
	}
	destroyFila(&f);
}




