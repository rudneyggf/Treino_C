#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularAlteradaFim.h"

Lista* minha_lista;

struct aluno al;

int main()
{
   minha_lista = criar_lista();
    printf("Lista criada! \n");
   for(int i=1;i<=500000;i++){
    al.matricula = 1;
    strcpy(al.nome,"Teste Joao");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;
    inserir_lista_final(minha_lista,al);

   }
    imprimir_lista(minha_lista);
    liberar_lista(minha_lista);
    printf("Lista liberada!");
}
