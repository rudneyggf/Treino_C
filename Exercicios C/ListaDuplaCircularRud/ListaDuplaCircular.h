#include <stdlib.h>
#include <stdio.h>

struct jogo{
char nome[30];
int codigo;
};

typedef struct descritor Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_lista_inicio(Lista *li, struct jogo g);
int inserir_lista_final(Lista* li, struct jogo g);
int inserir_lista_ordenada(Lista *li, struct jogo g);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);
int remover_lista(Lista* li, int codigo);
int busca_lista_mat(Lista* li, int codigo, struct jogo* g);
void imprimir_lista(Lista* li);

