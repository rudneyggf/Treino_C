/*
                                               SISTEMAS DE INFORMAÇÃO - IFMA-MC - 1º PERÍODO
                                                FUNDAMENTOS DE PROGRAMAÇÃO DE COMPUTADORES
                                          ATIVIDADE AVALIATIVA - ETAPA 3 - PROFESSORA SALETE FARIAS

                              Problema 1: Jogo de Adivinhação: Crie um jogo em que o computador seleciona um número
                        aleatório e o jogador precisa adivinhar qual é esse número. O jogo deve fornecer dicas sobre se o
                        número fornecido é maior ou menor do que o número a ser adivinhado. Os alunos podem utilizar
                        estruturas de repetição, como loops, para permitir várias tentativas e estruturas condicionais para
                        fornecer as dicas adequadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX_TENTATIVAS 3

int main() {

  int n = 0, x = 0, c = 0, t = 1, fdj = 0, cont = 0;

  setlocale(LC_ALL, "Portuguese");    // Suporte aos acentos no console.
  menuinicial();                        // Menu inicial.
  n = naleatorio(dificuldade());          // Atribuição de um número aleatório para 'n' pela 'função geradora' de acordo com a 'dificuldade' escolhida.
  cabecalho(n, x);                          // Função de cabeçalho da partida.
  //debug(n);                                 // FUNÇÃO PARA TESTES - deixar comentada.

  do {                                          // Loop que se repete até a variável 'fdj' (fim de jogo) mudar de '0' para '1'.

    if (c == 1 && t > MAX_TENTATIVAS) {
      t = 1;                   // O contador de tentativas precisa resetar a cada 'continue' solicitado após uma derrota e o console precisa ser limpo.
      cabecalho(n, x);
    }

    printf("====== PALPITE %d ==========================================\n", t);
    scanf("%d", &x);                  // Tentativa.
    printf("================================================ DICA =====\n\n");

      if (n == x) {

         vitoria(n);       // Tela de vitória.
         fdj = 1;

      } else {
                                // As dicas foram divididas e agrupadas dentro 'switches aleatórios' que existem de funções de mesmo nome.
        if (cont < 2) {           // A cada erro do jogador, uma dica nova é exibida seguindo um nível de dificuldade específico
          dicasdificeis(n, x);      // e, consequentemente, a dificuldade vai diminuindo conforme o jogador não vence a rodada.
        } else if (cont < 5) {
          dicasmedias(n, x);
        } else if (cont < 7) {
          dicasfaceis(n, x);
        } else {
          derrota(n);
          printf("                          ... Mais sorte na próxima.");
          fdj = 1;
        }

          t++;

            if (t > MAX_TENTATIVAS) {            // Se o número de tentativas passar de 'MAX_TENTATIVAS', o jogador perde a rodada.

              printf("\n                 Você perdeu, limite de tentativas alcançado!");
              printf("\n                 [1] Continuar  [2] Novo jogo  [3] Desistir\n");

              do {                                  // Loop que se repete até que uma opção válida seja escolhida, de acordo com as oferecidas
                                                      // ao final de uma rodada perdida.
                scanf("%d", &c);

                  if (c == 1) {                          // 'CONTINUE' - o recomeça com uma nova rodada com os mesmos parâmetros.
                      cont++;
                    break;
                  } else if (c == 2) {                       // 'NOVO JOGO' - todos os parâmetros são resetados e novamente escolhidos.
                      cont = 0;
                      t = 1;
                      menuinicial();
                      n = naleatorio(dificuldade());
                      cabecalho(n, x);
                    break;
                  } else if (c == 3) {                 // 'DESISTIR' - fim de jogo.
                      fdj = 1;
                      derrota(n);             // Tela de derrota.
                  }

              } while (c != 1 && c != 2);
          }
      }
  }while (fdj != 1);
}

/*
      DESENVOLVIDO PELOS ALUNOS:

- FELIPE SILVA    - DEV. ESTRUTURA
- GUILHERME JOSÉ  - DEV. ESTRUTURA E INTERFACE
- JOSÉ C. JÚNIOR  - DEV.
- LEANDRA LEANNE  - DEV. DICAS
- RUDNEY GABRIEL  - DEV. DICAS
*/
