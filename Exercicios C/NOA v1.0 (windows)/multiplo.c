int primo(int sorteado){            //Fun��o auxiliar para determinar se um n�mero � primo.
   int primo=0;                      // Vari�vel de auxil�o para servir como um boolean 'true' ou 'false'.
   for(int i=2;i<101;i++){            // La�o de repeti��o que engloba todos os valores de 2 a 100.
     if(i!=sorteado && sorteado%i==0 || sorteado<0 || sorteado==1){
/* Condi��es em que se o n�mero sorteado for diferente dele mesmo e o resto da divis�o dele por 'i' for diferente de 0, ser� classificado como n�o primo e encerrar� o la�o. La�o poder� ser encerrado tamb�m caso o n�mero seja negativo ou 1. */
       primo=0;
       break;
     }else{
       primo=1;
     }
    }
   if(primo==0){// Retorno 'true' ou 'false' necess�rio para a fun��o principal da dica.
       return 0;
     }else{
       return 1;
     }
  }

void multiplo(sorteado, palpite, red){// Fun��o principal desta dica.
if (red == 0) {
    if(primo(sorteado)==0){          //Bloco executado caso o n�mero n�o seja primo.
      int divisores[3]={3,5,7};      // Vetor que cont�m os divisores primos que usaremos.
      for(int i=2;i>=0;i--){        //La�o de repeti��o que come�a do �ltimo n�mero do vetor e vai at� o primeiro por meio de decremento da vari�vel 'i'.
        if(sorteado==0){          // Sequ�ncia de Estruturas Concionais que ser�o acionadas dependendo do n�mero sorteado e de seu maior m�ltiplo dos que existem no vetor.
          printf("O n�mero sorteado � m�ltiplo de todos os n�meros.\n");
          break;
        }else if(sorteado%divisores[i]==0){
          printf("O n�mero sorteado � m�ltiplo de '%d'.\n",divisores[i]);
          break;
        }else if(sorteado==1){
          printf("O n�mero sorteado � apenas m�ltiplo dele mesmo.\n");
          break;
        }
      }
    }else{                        // bloco ativado caso a fun��o axiliar determine que o n�mero � primo
      printf("O n�mero � primo.\n");
      }
  } else {
    dicasdificeis(sorteado, palpite);
  }
}
