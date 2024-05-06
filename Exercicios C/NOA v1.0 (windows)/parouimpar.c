// Calcula o resto da divisão por 2 para julgar se o número sorteado é par ou ímpar.

void parImp(int sorteado, int palpite, int red){
if (red == 0) {
  if(sorteado%2==0){
    printf("O número sorteado é par.\n");
  }else{
    printf("O número sorteado é ímpar.\n");
  }
 } else {
  dicasmedias(sorteado, palpite);
 }
}
