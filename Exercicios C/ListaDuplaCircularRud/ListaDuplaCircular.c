#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaCircular.h"

struct no{
 struct jogo game;
 struct no* prox;
 struct no* ant;
};

typedef struct no No;

struct descritor{
 int tamanho;
 No* inicio;
 No* fim;
};

Lista* criar_lista(){
    Lista* li=(Lista*) malloc(sizeof(Lista));
    if(li!=NULL){
        li->inicio=NULL;
        li->fim=NULL;
        li->tamanho=0;
    }
   return li;
}

void liberar_lista(Lista*li){
    if(li!=NULL){
         No* no;
         while(no!=li->fim){
            no=li->inicio;
            li->inicio=no->prox;
            free(no);
            }
    free(li);
    }
}

int tamanho_lista(Lista* li){
     if(li==NULL)
        return 0;
     return li->tamanho;
}

int inserir_lista_inicio(Lista* li, struct jogo g){
     if(li==NULL)
        return 0;
     No* no=(No*) malloc(sizeof(No));
     if(no==NULL)
        return 0;
     no->game=g;
     if(li->inicio==NULL){
        li->inicio=no;
        no->prox=no;
        no->ant=no;
        li->fim=no;
     }else{
       li->fim->prox=no;
       no->ant=li->fim;
       no->prox=li->inicio;
       li->inicio->ant=no;
       li->inicio=no;
     }
      li->tamanho++;
      return 1;
}


int inserir_lista_final(Lista* li,struct jogo g){
    if(li==NULL)
      return 0;
    No* no=(No*) malloc(sizeof(No));
    if(no==NULL)
      return 0;
    no->game=g;
    if(li->inicio==NULL){
        li->inicio=no;
        no->prox=no;
        no->ant=no;
        li->fim=no;
    }else{
       li->fim->prox=no;
       no->ant=li->fim;
       no->prox=li->inicio;
       li->inicio->ant=no;
       li->fim=no;
    }
    li->tamanho++;
    return 1;
}


int inserir_lista_ordenada(Lista* li,struct jogo g){
   if(li==NULL)
     return 0;
   No* no=(No*) malloc(sizeof(No));
   if(no==NULL)
    return 0;
    no->game=g;
     if(li->inicio==NULL){
        li->inicio=no;
        no->prox=no;
        no->ant=no;
        li->fim=no;
    }else{
     No* aux=li->inicio,*ant=li->fim;
   while(aux!=li->inicio && aux->game.codigo<g.codigo){
    ant=aux;
    aux=aux->prox;
   }
   no->prox=aux;
   no->ant=ant;
   ant->prox=no;
   aux->ant=no;
   if(aux==li->inicio)
        li->inicio=no;
   if(aux==li->fim)
        li->fim=no;
    }
    li->tamanho++;
    return 1;
}

int remover_lista_inicio(Lista* li){
    if(li==NULL)
        return 0;
    if(li->inicio==NULL)
        return 0;
    No* no=li->inicio;
    if(li->inicio==li->fim){
        no->prox=NULL;
        no->ant=NULL;
        li->inicio=NULL;
        li->fim=NULL;
    }else{
        li->fim->prox=no->prox;
        no->prox->ant=li->fim;
        li->inicio=no->prox;
    }
    free(no);
    li->tamanho--;
    return 1;
}

int remover_lista_final(Lista* li){
  if(li==NULL)
    return 0;
  if(li->inicio==NULL)
    return 0;
  No* no=li->fim;
  if(li->inicio==li->fim){
     no->prox=NULL;
     no->ant=NULL;
     li->inicio=NULL;
     li->fim=NULL;
  }else{
     li->fim->ant->prox=li->inicio;
     li->inicio->ant=li->fim->ant;
     li->fim=li->fim->ant;
  }
    free(no);
    li->tamanho--;
}

int remover_lista(Lista* li,int codigo){
 if(li==NULL)
    return 0;
 if(li->inicio==NULL)
    return 0;
 No*ante=li->inicio,*no=ante;
 while(no!=li->fim && no->game.codigo!=codigo){
    ante=no;
    no=no->prox;
 }
  if(no==li->fim && no->game.codigo!=codigo)
    return 0;
 if(li->inicio==li->fim){
     no->prox=NULL;
     no->ant=NULL;
     li->inicio=NULL;
     li->fim=NULL;
 }else if(no=li->inicio){
     li->fim->prox=no->prox;
     no->prox->ant=li->fim;
     li->inicio=no->prox;
 } else if(no==li->fim && no->game.codigo==codigo){
     li->fim->ant->prox=li->inicio;
     li->inicio->ant=li->fim->ant;
     li->fim=li->fim->ant;
 }else{
     ante->prox=no->prox;
     no->prox->ant=ante;
 }
  free(no);
  li->tamanho--;
  return 1;
}

int busca_lista_mat(Lista* li,int codigo,struct jogo *g ){
    if(li==NULL)
        return 0;
    No* no=li->inicio;
    while(no!=li->fim && no->game.codigo!=codigo)
        no=no->prox;
    if(no==li->fim && no->game.codigo!=codigo)
        return 0;
    *g=no->game;
    return 1;
}

void imprimir_lista(Lista* li){
    if (li == NULL||li->inicio==NULL){
       printf("Lista vazia\n");
       return 0;
    }
    No* ler_no = li->inicio;
    printf("-------------\n");
    do{
        printf("Codigo: %d\n", ler_no->game.codigo);
        printf("Nome: %s\n", ler_no->game.nome);
        printf("-------------\n");
        ler_no = ler_no->prox;
    }while(ler_no !=li->inicio);
    return 1;
}
