#include <stdio.h>
#include <stdlib.h>

struct Jogo{
 char nome[30];
 int codigo;
};

typedef struct elemento* Lista;

Lista* criar_lista();
int liberar_lista(Lista* li);
int inserir_lista_inicio(Lista* li, struct Jogo jogo);
int inserir_lista_final(Lista* li,struct Jogo jogo);
int inserir_lista_ordenada(Lista* li, struct Jogo jogo);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);
int remover_lista(Lista* li, int codigo);
int busca_lista_cod(Lista* li, int codigo, struct Jogo* jogo);
