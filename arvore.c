#include "arvore.h"

ARVORE *cria_arvore_vazia(){
    ARVORE *a;
    a = (ARVORE*) malloc (sizeof(ARVORE));
    a->raiz = NULL;
    return a;
}

/////////////////////////////////////////////////////////////
void libera_no(NO *aux){
    if(aux == NULL){
        return;
    }
    libera_no(aux->esq);
    libera_no(aux->dir);
    free(aux);
    aux = NULL;
}


void libera_arvore(ARVORE *a){
    if(a == NULL){
        return;
    }
    libera_no(a->raiz);
    free(a);
    a = NULL;
}

//////////////////////////////////////////////////////////
int arvore_vazia(ARVORE *a){
    if(a == NULL){
        return 1;
    }
    if(a->raiz == NULL){
        return 1;
    }
    else{
      return 0;
    }
}

//////////////////////////////////////////////////////////
int calculo_da_altura(NO *a){
    if(arvore_vazia == 1){
        return 0;
    }

    int alt_esq = altura_da_arvore(a->esq);
    int alt_dir = altura_da_arvore(a->dir);
    if(alt_dir > alt_esq){
        return alt_dir;
    }
    else{
        return alt_esq;
    }

}
int altura_da_arvore(ARVORE *a){
    NO *aux;
    aux = a->raiz;
    int altura = calculo_da_altura(aux);
    return altura;
}



//////////////////////////////////////////////////////////
int contador_de_nos(NO *a){
    if(a == NULL){
        return 0;
    }
    int alt_esq = altura_da_arvore(a->esq);
    int alt_dir = altura_da_arvore(a->dir);

    return (alt_dir + alt_esq + 1);
}
int qtd_de_nos(ARVORE *a){
    if(arvore_vazia == 1){
        return 0;
    }
    NO *aux;
    aux = a->raiz;
    int Total_de_nos = contador_de_nos(aux);

    return Total_de_nos;
}


//////////////////////////////////////////////////////////
void aux_pre_ordem(NO *aux){
    if(aux == NULL){
        return;
    }
    printf("[%d]%c || ",aux->chave,aux->infor);
    aux_pre_ordem(aux->esq);
    aux_pre_ordem(aux->dir);
}
void impressao_pre_ordem(ARVORE *a){
    if(arvore_vazia == 1){
        return;
    }
    NO * aux;
    aux = a->raiz;
    aux_pre_ordem(aux);
}

////////////////////////////////////////////////////////
void aux_em_ordem(NO *aux){
    if(aux == NULL){
        return;
    }
    aux_em_ordem(aux->esq);
    printf("[%d]%c || ",aux->chave,aux->infor);
    aux_em_ordem(aux->dir);
}
void impressao_em_ordem(ARVORE *a){
    if(arvore_vazia == 1){
        return;
    }
    NO * aux;
    aux = a->raiz;
    aux_em_ordem(aux);
}

////////////////////////////////////////////////////////

void aux_pos_ordem(NO *aux){
    if(aux == NULL){
        return;
    }
    aux_pos_ordem(aux->esq);
    aux_pos_ordem(aux->dir);
    printf("[%d]%c || ",aux->chave,aux->infor);
}
void impressao_pos_ordem(ARVORE *a){
    if(arvore_vazia == 1){
        return;
    }
    NO *aux;
    aux = a->raiz;
    aux_pos_ordem(aux);
}

////////////////////////////////////////////////////////

int cria_raiz(char inf,int chav,ARVORE *a){
    if(a == NULL){
        return 1;
    }
    NO *aux;
    aux = (NO*) malloc (sizeof(NO));
    if(aux == NULL){
        return NULL;
    }
    aux->chave = chav;
    aux->infor = inf;
    aux->esq = NULL;
    aux->dir = NULL;

    a->raiz = aux;

    return 0;
}

int insere(char inf,int chav,ARVORE *a){
    if(a->raiz == NULL){
      return cria_raiz(inf,chav,a);
    }
    else{
      NO *novo;
      novo =(NO*) malloc (sizeof(NO));
      if(novo == NULL){
          return 1;
      }
      novo->chave = chav;
      novo->infor = inf;
      novo->esq = NULL;
      novo->dir = NULL;

      NO *atual,*ant;
      atual = a->raiz;

        while(atual != NULL){
            ant = atual;
            if(chav == atual->chave){
                free(novo);
                return 1;
            }
              ////////////////////////
            if(chav > atual->chave){
               atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }


        if(chav > ant->chave){
              ant->dir = novo;
        }
        else{
              ant->esq = novo;
        }

      return 0;
    }
}

////////////////////////////////////////////////////////

NO *aux_remove(NO *atual){
    NO *aux1, *aux2;
    if(atual->esq == NULL){
        aux2 = atual->dir;
        free(atual);
        return aux2;
    }
    aux1 = atual;
    aux2 = atual->esq;
    while(aux2->dir != NULL){
        aux1 = aux2;
        aux2 = aux2->dir; 
    }
    if(aux1 != atual){
        aux1->dir = aux2->esq;
        aux2->esq = atual->esq;
    }
    aux2->dir = atual->dir;
    free(atual);
    return aux2;
    
    
}

int remocao(ARVORE *a, int valor){
    if(a->raiz == NULL){
        return 1;
    }
    NO *atual, *ant;
    atual = a->raiz;
    while(atual != NULL){
        if(valor == atual->chave){
            if(atual == a->raiz){
                a->raiz = aux_remove(atual);
            }
            else{
                if(ant->dir->chave == valor){
                    ant->dir = aux_remove(atual);
                }
                else{
                    ant->esq = aux_remove(atual);
                }
            }
            return 0;
        }
        ant = atual;
        
        if(atual->chave < valor){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
        
    }
    
    return 1;
}
//////////////////////////////////////////////////////////////////
int busca(ARVORE *a, int valor){
    
}






