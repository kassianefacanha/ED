#include "funcoes.h"
//funções do cabecalho
cabecalho* criar_cabecalho(cabecalho *cabeca, char *nome, int escolha_bebida, int *tamanho){
	cabecalho *novo = (cabecalho*) malloc(sizeof(cabecalho));
	strcpy(novo->nome, nome);
	novo->inicio_lista = NULL;
	novo->permissao_alterar = 1;
	novo->proximo = cabeca;
	*tamanho = *tamanho + 1;
	return novo;
}

bool excluir_cabecalho(cabecalho *cabeca, char *nome, int *tamanho){
	if(*tamanho == 0){ //nenhuma lista?
		printf("não existe nenhuma lista!\n");
		return 0;
	}
	else{
		cabecalho *temp = cabeca; //PONTEIRO PARA PERCORRER A LISTA
		cabecalho *anterior = NULL; //PONTEIRO PARA GUARDAR O ANTERIOR

		for(int i=0 ; i<*tamanho ; i++){
			if(strcmp(nome, temp->nome)==0){
				if(i>0) anterior->proximo = temp->proximo; //reorganizar a lista de "principal"
				else{
					cabeca = cabeca->proximo;
				}
					*tamanho = *tamanho - 1;
				//falta desalocar todas as células de bebidas ou comidas de "deletar"
				free(temp);//desalocar "deletar"
				printf("a lista %s foi excluida\n", nome);
				return 1;
			}
			anterior = temp;
			temp = temp->proximo;
		}
	}
	printf("não existe nenhuma lista com esse nome!");
	return 0; // não encontrada
}
cabecalho* find_cabecalho(cabecalho *cabeca, char *nome, int *tamanho){
	cabecalho *temp = cabeca;
	for(int i=0 ; i<*tamanho; i++, temp = temp->proximo){
		if(strcmp(nome, temp->nome)==0){
			return temp;
		}
	}
	return NULL;
}

bool exibir_cabecalhos(cabecalho *pai, int *tamanho){
	cabecalho *temp = pai;
	if(*tamanho == 0){
		printf("não existe nenhuma lista!\n");
		return 0;
	}
	else{
		printf("As listas existentes são: \n");
		for(int i=0; i< *tamanho ; i++){
			printf("%s\n",temp->nome);
			temp = temp->proximo;
		}
	return 1;
	}
}
void salvar_lista();

//funções de comida e bebida
void adicionar_produto();
void remover_produto();
void ultima_vez_comprado();
