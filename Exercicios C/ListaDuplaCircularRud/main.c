#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaCircular.h"
#include <string.h>

int main(){
Lista* listaGames=criar_lista();

struct jogo g;
struct jogo j;
g.codigo=1;
strcpy(g.nome,"MetalGear");
int x=inserir_lista_inicio(listaGames,g);

g.codigo=2;
strcpy(g.nome,"Castlevania");
inserir_lista_final(listaGames,g);

g.codigo=4;
strcpy(g.nome,"Sonic");
inserir_lista_final(listaGames,g);

g.codigo=3 ;
strcpy(g.nome,"DMC");
inserir_lista_ordenada(listaGames,g);
imprimir_lista(listaGames);

printf("\n\n");
busca_lista_mat(listaGames,4,&j);
printf("%s",j.nome);
liberar_lista(listaGames);

}
