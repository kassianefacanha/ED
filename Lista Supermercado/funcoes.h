#ifndef funcoes_h
#define funcoes_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//structs
typedef struct{
	int tamanho;
	char *nome;
	int codigo;
	bool vegetariano;
	void *proximo_produto;
	int tempo;
}comidas;

typedef struct{
	int tamanho;
	char *nome;
	int codigo;
	bool alcoolica;
	void *proximo_produto;
}bebidas;

struct CABECALHO{
	bool permissao_alterar;
	char nome[31];
	void *inicio_lista;
	struct CABECALHO *proximo;
};typedef struct CABECALHO cabecalho;

//funções do cabeçalho
cabecalho* criar_cabecalho(cabecalho *cabeca, char *nome, int escolha_bebida, int *tamanho);
cabecalho* find_cabecalho(cabecalho *cabeca, char *nome, int *tamanho);
bool excluir_cabecalho(cabecalho *cabeca, char *nome, int *tamanho);
bool exibir_cabecalhos(cabecalho *pai, int *tamanho);
void salvar_lista();

//funções de comida e bebida
void adicionar_produto();
void remover_produto();
void ultima_vez_comprado();
#endif
/*
int strcmp ( const char * str1, const char * str2 );int st
return value	indicates
<0	the first character that does not match has a lower value in ptr1 than in ptr2
0	the contents of both strings are equal
>0	the first character that does not match has a greater value in ptr1 than in ptr2
*/
