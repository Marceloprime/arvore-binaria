#include "arvore.h"
#include <stdio.h>
#include <time.h>

int main(){
    ARVORE *a;
    int i,aux;
    a = cria_arvore_vazia();

    for(i = 0;i<10;i++){
        aux = (rand()%50);
        insere((i+65),aux,a);
    }

    impressao_pre_ordem(a);
    printf("\n");
    impressao_em_ordem(a);
    printf("\n");
    impressao_pos_ordem(a);
    printf("\n\n");
    
    
    

    remocao(a,0);
    impressao_pre_ordem(a);
    printf("\n");
    


    libera_arvore(a);

    return 0;
}
