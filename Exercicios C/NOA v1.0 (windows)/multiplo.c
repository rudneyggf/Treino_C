int primo(int sorteado){            //Função auxiliar para determinar se um número é primo.
   int primo=0;                      // Variável de auxilío para servir como um boolean 'true' ou 'false'.
   for(int i=2;i<101;i++){            // Laço de repetição que engloba todos os valores de 2 a 100.
     if(i!=sorteado && sorteado%i==0 || sorteado<0 || sorteado==1){
/* Condições em que se o número sorteado for diferente dele mesmo e o resto da divisão dele por 'i' for diferente de 0, será classificado como não primo e encerrará o laço. Laço poderá ser encerrado também caso o número seja negativo ou 1. */
       primo=0;
       break;
     }else{
       primo=1;
     }
    }
   if(primo==0){// Retorno 'true' ou 'false' necessário para a função principal da dica.
       return 0;
     }else{
       return 1;
     }
  }

void multiplo(sorteado, palpite, red){// Função principal desta dica.
if (red == 0) {
    if(primo(sorteado)==0){          //Bloco executado caso o número não seja primo.
      int divisores[3]={3,5,7};      // Vetor que contém os divisores primos que usaremos.
      for(int i=2;i>=0;i--){        //Laço de repetição que começa do último número do vetor e vai até o primeiro por meio de decremento da variável 'i'.
        if(sorteado==0){          // Sequência de Estruturas Concionais que serão acionadas dependendo do número sorteado e de seu maior múltiplo dos que existem no vetor.
          printf("O número sorteado é múltiplo de todos os números.\n");
          break;
        }else if(sorteado%divisores[i]==0){
          printf("O número sorteado é múltiplo de '%d'.\n",divisores[i]);
          break;
        }else if(sorteado==1){
          printf("O número sorteado é apenas múltiplo dele mesmo.\n");
          break;
        }
      }
    }else{                        // bloco ativado caso a função axiliar determine que o número é primo
      printf("O número é primo.\n");
      }
  } else {
    dicasdificeis(sorteado, palpite);
  }
}
