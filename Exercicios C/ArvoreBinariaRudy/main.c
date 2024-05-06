#include <stdio.h>
#include <stdlib.h>
#include "ArvoreRudy.h"

ArvBin* raiz;

int main()
{
  raiz=cria_arvore();
  inserir_arvore(raiz,10);
  inserir_arvore(raiz,5);
  inserir_arvore(raiz,20);
  inserir_arvore(raiz,15);
  pre_ordem(raiz);
  printf("\n");
  remover_arvore(raiz,15);
  pre_ordem(raiz);
  libera_arvore(raiz);

}
