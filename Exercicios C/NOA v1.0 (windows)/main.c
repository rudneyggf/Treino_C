/*
                                               SISTEMAS DE INFORMA��O - IFMA-MC - 1� PER�ODO
                                                FUNDAMENTOS DE PROGRAMA��O DE COMPUTADORES
                                          ATIVIDADE AVALIATIVA - ETAPA 3 - PROFESSORA SALETE FARIAS

                              Problema 1: Jogo de Adivinha��o: Crie um jogo em que o computador seleciona um n�mero
                        aleat�rio e o jogador precisa adivinhar qual � esse n�mero. O jogo deve fornecer dicas sobre se o
                        n�mero fornecido � maior ou menor do que o n�mero a ser adivinhado. Os alunos podem utilizar
                        estruturas de repeti��o, como loops, para permitir v�rias tentativas e estruturas condicionais para
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
  n = naleatorio(dificuldade());          // Atribui��o de um n�mero aleat�rio para 'n' pela 'fun��o geradora' de acordo com a 'dificuldade' escolhida.
  cabecalho(n, x);                          // Fun��o de cabe�alho da partida.
  //debug(n);                                 // FUN��O PARA TESTES - deixar comentada.

  do {                                          // Loop que se repete at� a vari�vel 'fdj' (fim de jogo) mudar de '0' para '1'.

    if (c == 1 && t > MAX_TENTATIVAS) {
      t = 1;                   // O contador de tentativas precisa resetar a cada 'continue' solicitado ap�s uma derrota e o console precisa ser limpo.
      cabecalho(n, x);
    }

    printf("====== PALPITE %d ==========================================\n", t);
    scanf("%d", &x);                  // Tentativa.
    printf("================================================ DICA =====\n\n");

      if (n == x) {

         vitoria(n);       // Tela de vit�ria.
         fdj = 1;

      } else {
                                // As dicas foram divididas e agrupadas dentro 'switches aleat�rios' que existem de fun��es de mesmo nome.
        if (cont < 2) {           // A cada erro do jogador, uma dica nova � exibida seguindo um n�vel de dificuldade espec�fico
          dicasdificeis(n, x);      // e, consequentemente, a dificuldade vai diminuindo conforme o jogador n�o vence a rodada.
        } else if (cont < 5) {
          dicasmedias(n, x);
        } else if (cont < 7) {
          dicasfaceis(n, x);
        } else {
          derrota(n);
          printf("                          ... Mais sorte na pr�xima.");
          fdj = 1;
        }

          t++;

            if (t > MAX_TENTATIVAS) {            // Se o n�mero de tentativas passar de 'MAX_TENTATIVAS', o jogador perde a rodada.

              printf("\n                 Voc� perdeu, limite de tentativas alcan�ado!");
              printf("\n                 [1] Continuar  [2] Novo jogo  [3] Desistir\n");

              do {                                  // Loop que se repete at� que uma op��o v�lida seja escolhida, de acordo com as oferecidas
                                                      // ao final de uma rodada perdida.
                scanf("%d", &c);

                  if (c == 1) {                          // 'CONTINUE' - o recome�a com uma nova rodada com os mesmos par�metros.
                      cont++;
                    break;
                  } else if (c == 2) {                       // 'NOVO JOGO' - todos os par�metros s�o resetados e novamente escolhidos.
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
- GUILHERME JOS�  - DEV. ESTRUTURA E INTERFACE
- JOS� C. J�NIOR  - DEV.
- LEANDRA LEANNE  - DEV. DICAS
- RUDNEY GABRIEL  - DEV. DICAS
*/
