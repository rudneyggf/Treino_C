
#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularAlteradaFim.h"

struct no{
    struct aluno dados;
    struct no *prox;
};

typedef struct no No;

Lista* criar_lista(){
    Lista * li = (Lista*) malloc (sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void liberar_lista(Lista* li){
    if (li != NULL && (*li)->prox != NULL){//alteração
        No *aux, *no = *li;
        while((*li)!= no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if (li == NULL || (*li)->prox == NULL)//alteração
        return 0;
    int cont = 0;
    No* no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no != (*li));
    return cont;
}

int lista_vazia(Lista* li){
    if (li == NULL)
        return 1;
    if ((*li)->prox == NULL)
        return 1;
    return 0;
}

int inserir_lista_inicio(Lista *li, struct aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    if((*li) == NULL){//alteração
        *li = novo_no;
        novo_no->prox = novo_no;
    } else {
        //alteração
        novo_no->prox=(*li)->prox;
        (*li)->prox=novo_no;
    }
    return 1;
}

int inserir_lista_final(Lista *li, struct aluno al){
    if (li == NULL)
        return 0;
    No *novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    if((*li) == NULL){//alteração
        *li = novo_no;
        novo_no->prox = novo_no;
    } else {
       //alteração
        novo_no->prox=(*li)->prox;
       (*li)->prox=novo_no;
       *li=novo_no;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    if((*li) == NULL){//alteração
        *li = novo_no;
        novo_no->prox = novo_no;
        return 1;
    }else{
        if((*li)->prox->dados.matricula > al.matricula){
            novo_no->prox=(*li)->prox;
           (*li)->prox=novo_no;
            return 1;
        }
       if((*li)->dados.matricula > al.matricula){
             //alteração
              novo_no->prox=(*li)->prox;
             (*li)->prox=novo_no;
              *li=novo_no;
              return 1;
           }
        No *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = novo_no;
        novo_no->prox = atual;
        return 1;
    }
}

int remover_lista_inicio(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li)->prox == NULL) //alteração
        return 0;

    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    //alteração
    No* no=(*li)->prox;
    (*li)->prox=no->prox;
    free(no);
    return 1;
}

int remover_lista_final(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li)->prox == NULL)//alteração
        return 0;

    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    No *ant=(*li)->prox, *no = *li;
    while(ant->prox != (*li)){
        //alteração
        ant=ant->prox;
    }
    //alteração
    ant->prox = no->prox;
    *li=ant;
    free(no);
    return 1;
}

int remover_lista(Lista* li, int mat){
    if (li == NULL)
        return 0;
    if ((*li)->prox == NULL)
        return 0;

    No *no = *li;
    if(no->dados.matricula == mat){
        if(no == no->prox){
            free(no);
            *li = NULL;
            return 1;
        }else{
           No *ant=(*li)->prox;
             while(ant->prox != (*li)){
               //alteração
               ant=ant->prox;
               }
           //alteração
           ant->prox = no->prox;
          *li=ant;
            free(no);
            return 1;
        }
    }
    No *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if (no == *li)
        return 0;
    ant->prox = no->prox;
    free(no);
    return 1;
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al){
    if (li == NULL || (*li)->prox==NULL)//alteração
        return 0;
    No *no = *li;
    while(no->prox != (*li) && no->dados.matricula != mat)
        no = no->prox;
    if (no->dados.matricula != mat)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}


void imprimir_lista(Lista* li){
    if (li == NULL){
       printf("Lista vazia\n");
       return 0;
    }
    No* ler_no = (*li)->prox; //alteração
    printf("-------------\n");
    do{
        printf("Matricula: %d\n", ler_no->dados.matricula);
        printf("Nome: %s\n", ler_no->dados.nome);
        printf("Notas: %2.1f %2.1f %2.1f\n", ler_no->dados.n1, ler_no->dados.n2, ler_no->dados.n3);
        printf("-------------\n");
        ler_no = ler_no->prox;
    }while(ler_no != (*li)->prox);//alteração
    return 1;
 }
