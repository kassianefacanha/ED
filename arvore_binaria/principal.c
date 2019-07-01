#include "arvore_binaria.h"

arvore_binaria *f(int valor, arvore_binaria *esq, arvore_binaria *dir){
	return createWithChildren(valor,esq,dir);
}

int main(){
	arvore_binaria *bt = 
		f(1,
			f(2,
				f(5,
					create(12),
					NULL),
				f(9,
					NULL,
					f(16,
						create(-1),
						NULL))),
			f(3,
				create(4),
				NULL)
		);
	printf("Numero de folhas: %d\n", sheets(bt));
	printf("Numero de nós: %d\n", size(bt));
	printf("Altura: %d\n", height(bt));
	printf("Buscar 9: %d, 16: %d, -1: %d, 20: %d\n", find(bt, 9), find(bt, 16), find(bt, -1), find(bt, 20));
	printf("Nível 9: %d, 16: %d, -1: %d, 20: %d\n", level(bt, 9), level(bt, 16), level(bt, -1), level(bt, 20));
	printf("Pre: "); printPreOrder(bt); printf("\n");
	printf("Pos: "); printPosOrder(bt); printf("\n");
	printf("In: "); printInOrder(bt); printf("\n");
	printf("Nível: "); printInLevel(bt); printf("\n");
	destroy(bt);
	return 0;
}










