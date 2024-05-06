#include <stdlib.h>
#include <stdio.h>
#include "ArvoreRudy.h"

struct No{
int valor;
struct No* esq;
struct No* dir;
};

typedef struct No No;

ArvBin* cria_arvore(){
  ArvBin* raiz=(ArvBin*) malloc(sizeof(ArvBin));
  if(raiz!=NULL)
      *raiz=NULL;
  return raiz;
}

int libera_arvore(ArvBin* raiz){
   if(raiz==NULL||*raiz==NULL)
    return 0;
  libera_arvore(&((*raiz)->esq));
  libera_arvore(&((*raiz)->dir));
  free(raiz);
  raiz=NULL;
  return 1;
}

int pre_ordem(ArvBin* raiz){
  if(raiz==NULL||*raiz==NULL)
    return 0;
   printf("%d ",(*raiz)->valor);
   pre_ordem(&((*raiz)->esq));
   pre_ordem(&((*raiz)->dir));
   return 1;
}

int em_ordem(ArvBin* raiz){
  if(raiz==NULL||*raiz==NULL)
    return 0;
   em_ordem(&((*raiz)->esq));
   printf("%d ",(*raiz)->valor);
   em_ordem(&((*raiz)->dir));
   return 1;
}

int pos_ordem(ArvBin* raiz){
  if(raiz==NULL||*raiz==NULL)
    return 0;
   pos_ordem(&((*raiz)->esq));
   pos_ordem(&((*raiz)->dir));
   printf("%d ",(*raiz)->valor);
   return 1;
}

int inserir_arvore(ArvBin* raiz,int valor){
 if(raiz==NULL)
    return 0;
 No* novo = (No*) malloc(sizeof(No));
 novo->dir=NULL;
 novo->esq=NULL;
 novo->valor=valor;

  if(*raiz==NULL){
    *raiz=novo;
     return 1;
  }
    No* ant=NULL,*atual=*raiz;
    while(atual!=NULL){
        ant=atual;
        if(valor==atual->valor){
            free(novo);
            return 0;
        }
        if(valor>atual->valor)
            atual=atual->dir;
        else
            atual=atual->esq;
  }
    if(valor>ant->valor)
        ant->dir=novo;
    else
        ant->esq=novo;
    return 1;

}


No* remover_atual(No* atual){
   No* no1,*no2;
   if(atual->esq==NULL){
      no2=atual->dir;
      free(atual);
      return no2;
   }
   no1=atual;
   no2=atual->esq;

   while(no2->dir!=NULL){
      no1=no2;
      no2=no2->dir;
   }

   if(no1!=atual){
     no1->dir=no2->esq;
     no2->esq=atual->esq;
   }
   no2->dir=atual->dir;
   free(atual);
   return no2;
}


int remover_arvore(ArvBin* raiz, int valor){
   if(raiz==NULL) return 0;
   No* ant=NULL,*atual=*raiz;
   while(atual!= NULL){
        if(atual->valor==valor){
            if(atual==*raiz)
                *raiz=remover_atual(atual);
            if(atual==ant->dir)
                ant->dir=remover_atual(atual);
            else
                ant->esq=remover_atual(atual);
             return 1;
        }
        ant=atual;
        if(valor>atual->valor)
            atual=atual->dir;
        else
            atual=atual->esq;
   }
}

int consulta_arvore(ArvBin* raiz, int valor){
     if(raiz=NULL)
        return 0;
     No* atual=*raiz;
     while(atual!=NULL){
         if(atual->valor==valor)
            return 1;
         if(valor>atual->valor)
            atual=atual->dir;
         else
            atual=atual->esq;
     }
       return 0;
}

