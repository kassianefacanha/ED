#include "arvore.h"

arvore *f(int valor, arvore* v[], int n){
	return createWithChildren(valor,v, n);
}

int main(){
	arvore* v12[] = {create(12)};
	arvore* v14[] = {create(14)};
	arvore* v0[] = {create(0)};
	arvore* v4[] = {create(4)};
	arvore* v3[] = {create(3)};
	arvore* v8[] = {f(8,v12,1)};
	arvore* v9[] = {f(9,v14,1)};
	arvore* vm1[] = {f(-1,v4,1)};
	
	
	arvore* f10[] = {v0[0], vm1[0], v3[0]};
	arvore* v10[] = {f(10,f10,3)};
	
	arvore *f5[] = {v8[0], v9[0], v10[0]};
	arvore* t = f(5, f5, 3); 
	
	
	printf("Numero de folhas: %d\n", sheets(t));
	printf("Numero de nós: %d\n", size(t));
	printf("Altura: %d\n", height(t));
	printf("Buscar 9: %d, 16: %d, -1: %d, 20: %d\n", find(t, 9), find(t, 16), find(t, -1), find(t, 20));
	printf("Nível 9: %d, 16: %d, -1: %d, 20: %d\n", level(t, 9), level(t, 16), level(t, -1), level(t, 20));
	printf("Pre: "); printPreOrder(t); printf("\n");
	printf("Pos: "); printPosOrder(t); printf("\n");
	printf("Nível: "); printInLevel(t); printf("\n");
	destroy(t);
	return 0;
}










