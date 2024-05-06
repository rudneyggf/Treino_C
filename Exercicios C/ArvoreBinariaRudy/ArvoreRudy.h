#include <stdio.h>
#include <stdlib.h>


typedef struct No* ArvBin;

ArvBin* cria_arvore();
int libera_arvore(ArvBin* raiz);
int pre_ordem(ArvBin* raiz);
int em_ordem(ArvBin* raiz);
int pos_ordem(ArvBin* raiz);
int inserir_arvore(ArvBin* raiz,int valor);
int remover_arvore(ArvBin* raiz,int valor);
int consulta_arvore(ArvBin* raiz,int valor);

