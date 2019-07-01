#include "abb.h"
#include "fila.h"
#include "abb.c"
#include "fila.c"
int raio = 20;
void print(abb *bt){
	if(empty(bt)) return;
	printf("%d %d %d\n", bt->valor, bt->x , bt->y);
	print(bt->esq);
	print(bt->dir);
}

void ler_arquivo(abb **raiz, int *n){
	int i;
	int valor;
	FILE *f = fopen("entrada.txt", "r");
	fscanf(f,"%d",n);
	for(i=0 ; i<*n; i++){
			fscanf(f,"%d", &valor);
			//colocando na árvore
			if(raiz != NULL)
			insert(raiz, valor);
	}
    fclose(f);
}

void escrever_arquivo(abb *raiz, int n, int x , int y, int raio){
	FILE *f = fopen("saida.txt", "w");
	fprintf(f,"%d %d %d",x, y, raio);
	printPreOrder(raiz, f);		 
    fclose(f);
}
void atualizaXY(abb **raiz, int x, int y, int largura, int divisor){
	if(*raiz == NULL) return;
	else {
		(*raiz)->x = x;
		(*raiz)->y = y;
	} 
	atualizaXY(&(*raiz)->dir, x+(largura/divisor), y+2*raio, largura ,divisor*2); //atualiza toda direita
	atualizaXY(&(*raiz)->esq, x-(largura/divisor), y+2*raio, largura ,divisor*2); //atualiza toda esquerda
}

int main(){
	int n;
	abb *raiz = NULL;
	ler_arquivo(&raiz, &n);
	
	int raio, x, y; // x e y representa a altura e largura da imagem em pixel 
	raio = 30;
	int altura = height(raiz); //altura da árvore binária
			
	y = 4*raio*(altura+1)+raio;
		//??? não sei mais porque esses valores, mas tá dando certo, fiz ele fazendo desenhos, mas perdi
	x = 1.3*(2*raio+(altura*altura)*(2*raio)+(altura*altura-1)*raio);

	int divisor = 4;	
	atualizaXY(&raiz, x/2, raio, x, divisor);
	printf("o arquivo está sendo gravado:\n");	
	escrever_arquivo(raiz, n, x , y , raio);
	return 0;
}
