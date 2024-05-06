#include <stdlib.h>
#include <stdio.h>
#include "ListaC.h"

struct elemento{
struct Jogo jogo;
struct elemento* prox;
};

typedef struct elemento Elem;
Lista* li;

Lista* criar_lista(){
    Lista *li=(Lista*) malloc(sizeof(Lista));
    if(li!=NULL)
     *li=NULL;
    return li;
}

int liberar_lista(Lista* li){
    if(li!=NULL && (*li) !=NULL){
        Elem* aux, *no=li;
        while((*li)!=no->prox){
            aux=no;
            no=no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }

}

int inserir_lista_inicio(Lista* li, struct Jogo jogo){
    if(li==NULL)
        return 0;
    Elem* no= (Elem*) malloc(sizeof(Elem));
    if(no==NULL)
        return 0;
    no->jogo=jogo;
    if((*li)==NULL){
        *li=no;
        no->prox=no;
    }else{
        Elem* aux= *li;
        while(aux->prox!=*li)
           aux=aux->prox;
         aux->prox=no;
         no->prox=*li;
         *li=no;
         return 1;
    }
}


int inserir_lista_final(Lista* li,struct Jogo jogo){
    if(li=NULL)
        return 0;
    Elem* no=(Elem*) malloc(sizeof(Elem));
    if(no==NULL)
        return 0;
    no->jogo=jogo;
    if((*li)==NULL){
        *li=no;
        no->prox=no;
        return 1;
    }else{
       Elem* aux=*li;
       while(aux->prox!=*li)
        aux=aux->prox;
       aux->prox=no;
       no->prox=*li;
       return 1;
    }

}


int inserir_lista_ordenada(Lista* li,struct Jogo jogo){
   if(li==NULL)
    return 0;
   Elem* no= (Elem*) malloc(sizeof(Elem));
   if(no==NULL)
    return 0;
   if((*li)->prox=*li){
      *li=no;
      no->prox=no;
      return 1;
   }else if ((*li)->jogo.codigo>jogo.codigo){
            Elem* aux=*li;
            while(aux->prox!=*li)
              aux=aux->prox;
            aux->prox=no;
            no->prox=*li;
            *li=no;
            return 1;
       }
       Elem* ant=*li, *aux=(*li)->prox;
      while(aux->prox!=*li && jogo.codigo>aux->jogo.codigo){
         ant=aux;
         aux=aux->prox;
      }
      ant->prox=no;
      no->prox=aux;
        return 1;
   }

int remover_lista_inicio(Lista* li){
   if(li==NULL)
    return 0;
   if(*li==NULL)
    return 0;
   Elem* no=*li,*aux=*li;
   while(aux->prox!=*li)
    aux=aux->prox;
   if(aux->prox==no->prox){
     aux->prox=NULL;
     no->prox=aux->prox;
   }else{
     aux->prox=no->prox;
     *li=no->prox;
   }
   free(no);
   return 1;
}

