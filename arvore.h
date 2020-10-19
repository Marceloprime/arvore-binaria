#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct arv{
    int chave;
    char infor;
    struct arv *esq;
    struct arv *dir;
}NO;

typedef struct{
    NO *raiz;
}ARVORE;



ARVORE *cria_arvore_vazia();
int insere(char inf,int chav,ARVORE *a);
void libera_arvore(ARVORE *a);
int arvore_vazia(ARVORE *a);
int altura_da_arvore(ARVORE *a);
int qtd_de_nos(ARVORE *a);
void impressao_pre_ordem(ARVORE *a);
void impressao_em_ordem(ARVORE *a);
void impressao_pos_ordem(ARVORE *a);

int remocao(ARVORE *a, int valor);


#endif // ARVORE_H_INCLUDED
