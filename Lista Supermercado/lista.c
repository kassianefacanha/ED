#include "funcoes.h"
#include "funcoes.c"
	int main(){
	int opcao;
	char nome[31];

	cabecalho *cabeca;
	int *tamanho = malloc(sizeof(int));
	*tamanho = 0;

	do{
		printf("1-criar lista\n2-excluir lista\n3-acessar lista\n4-mostrar listas existentes\n0-sair: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 0:{
				printf("programa encerrado");
				break;
			}
			case 1:{
				int escolha_bebida;
				printf("opções:\n1- para criar uma lista de bebidas\n2- para criar uma lista de comidas\ndigite:");
				scanf("%d",&escolha_bebida);
				printf("digite um nome para sua lista de compras: ");
				scanf("\n%30[^\n]",nome);
				cabeca = criar_cabecalho(cabeca, nome, escolha_bebida, tamanho);
				printf("lista criada\n");
				break;
			}
			case 2:{
				if(exibir_cabecalhos(cabeca, tamanho)==1){
					printf("existem %d listas de compras\n",*tamanho);
					printf("nome da lista que será excluída? ");
					scanf("\n\n%25[^\n]",nome);
					excluir_cabecalho(cabeca, nome, tamanho);
				}
				break;
			}
			case 3:{
				if(*tamanho > 0){
					int opcao2;
					do{
						cabecalho *temp;
						exibir_cabecalhos(cabeca, tamanho);
						printf("Escolha uma lista para acesar: ");
						scanf("\n\n%25[^\n]",nome);
						//procurar se existe esse cabeçalho
						temp = find_cabecalho(cabeca, nome, tamanho);
						if(temp != NULL){
							printf("voce está acessando a lista '%s'\n",nome);
							printf("opcoes\n");
							printf("1-adicionar produto na lista\n");
							printf("2-remover produto da lista\n");
							printf("3-salvar a lista(nao podera mais ser alterada)\n");
							printf("4-verificar a ultima vez que um produto foi comprado\n");
							printf("5-voltar para o menu principal\n");
							printf("Selecione:");
							scanf("%d",& opcao2);
							switch(opcao2){
								case 1:{

									break;
								}
								case 2:{
									break;
								}
								case 3:{
									break;
								}
								case 4:{
									break;
								}
								case 5:{
									printf("voltando para o menu principal...\n");
									break;
								}
								default:{
									printf("opcao inválida");
									break;
								}
							}
						}
						else{
							printf("lista não encontrada!\n");
						}
					}while(opcao2!=5);
				}
				else{
					printf("não existe nenhuma lista de compras\n");
				}
				break;
			}
			case 4:{
				exibir_cabecalhos(cabeca, tamanho);
				break;
			}
			default:{
				printf("opcao invalida\n");
				break;
			}
		}
	}while(opcao != 0);
}
