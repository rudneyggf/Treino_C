// FUNÇÃO PENSADA PARA 10 DICAS DIFERENTES ('case's de 0 a 9) EM 3 NÍVEIS DE DIFICULDADE (FÁCIL, MÉDIO E DIFÍCIL).
// Variáveis: 'n' para o número sorteado e 'x' para o número escolhido pelo jogador.
// Cada vez que uma dica aparece dentro de um 'case', sua probabilidade de aparecer aumenta em '1/DICAS';

#define DICAS 9
#define TESTE 5

void dicasiniciais (n, x) {
  int op, probdic, r = 0;
  
  op = rand()%DICAS;

  //============DEBUG==============
  //printf("DICA INICIAL NÚMERO '%d'\n", op);  // Exibe qual case foi escolhido.
  //op = TESTE;                              // Fixa o jogo em uma dica.
  //===============================
  
  switch (op) {             
        case 0:
          parImp(n, r);
          r++;
    break;
        case 1:
          somaproduto(n);
    break;
        case 2:
          comparaTamanho(n, x);
    break;
        case 3:
          parImp(n, r);
          r++;
    break;
        case 4:
          binario(n);
    break;
        case 5:
          multiplo(n, x, r);
          r++;
    break;
        case 6:
          multiplo(n, x, r);
          r++;
    break;
        case 7:
          sinalNumero(n);
    break;
        case 8:
          fibonacci(n);
    break;
        case 9:
          ultimoDigito(n, x);
    break;
  }
printf("\n\n");
}

void dicasfaceis (n, x) {
  int op, probdic, r;
  
  op = rand()%DICAS;

  //============DEBUG==============
  //printf("DICA FÁCIL NÚMERO '%d'\n", op);  // Exibe qual case foi escolhido.
  //op = TESTE;                        // Fixa o jogo em uma dica.
  //===============================

  r++;

  switch (op) {             
        case 0:
         binario(n);
    break;
        case 1:
         binario(n);
    break;
        case 2:
          binario(n);
    break;
        case 3:
          binario(n);
    break;
        case 4:
          binario(n);
    break;
        case 5:
          fibonacci(n);
    break;
        case 6:
          fibonacci(n);
    break;
        case 7:
          fibonacci(n);
    break;
        case 8:
          comparaTamanho(n, x);
    break;
        case 9:
          comparaTamanho(n, x);
    break;
  } 
printf("\n\n");
}

void dicasmedias (n, x) {
  int op, probdic, r = 0;
  
  op = rand()%DICAS;

  //============DEBUG==============
  //printf("DICA MÉDIA NÚMERO '%d'\n", op);  // Exibe qual case foi escolhido.
  //op = TESTE;                        // Fixa o jogo em uma dica.
  //===============================
  
  switch (op) {             
        case 0:
         comparaTamanho(n, x);
    break;
        case 1:
         comparaTamanho(n, x);
    break;
        case 2:
          comparaTamanho(n, x);
    break;
        case 3:
          parImp(n, x, r);
          r++;
    break;
        case 4:
          comparaTamanho(n, x);
    break;
        case 5:
          multiplo(n, x, r);
          r++;
    break;
        case 6:
          comparaTamanho(n, x);
    break;
        case 7:
          sinalNumero(n);
    break;
        case 8:
          comparaTamanho(n, x);
    break;
        case 9:
          ultimoDigito(n, x);
    break;
  }
printf("\n\n");
}

void dicasdificeis (n, x) {
  int op, probdic, r = 0;

  op = rand() % DICAS;

//============DEBUG==============
//printf("DICA DIFÍCIL NÚMERO '%d'\n", op);  // Exibe qual case foi escolhido.
//op = TESTE;                        // Fixa o jogo em uma dica.
//===============================

  switch (op) {
        case 0:
          if (n >= 10) {
            somaproduto(n); }
          else {
            dicasdificeis(n, x);
                }
          break;
        case 1:
          if (n >= 10) {
            somaproduto(n); }
          else {
            dicasdificeis(n, x);
                }
          break;
        case 2:
        comparaTamanho(n, x);
          break;
        case 3:
        comparaTamanho(n, x);
          break;
        case 4:
        fibonacci(n);
          break;
        case 5:
        fibonacci(n);
          break;
        case 6:
        comparaTamanho(n, x);
          break;
        case 7:
        ultimoDigito(n, x);
          break;
        case 8:
        ultimoDigito(n, x);
          break;
        case 9:
        sinalNumero(x);
          break;
  }
  printf("\n\n");
}