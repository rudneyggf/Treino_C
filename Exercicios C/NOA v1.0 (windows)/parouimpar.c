// Calcula o resto da divis�o por 2 para julgar se o n�mero sorteado � par ou �mpar.

void parImp(int sorteado, int palpite, int red){
if (red == 0) {
  if(sorteado%2==0){
    printf("O n�mero sorteado � par.\n");
  }else{
    printf("O n�mero sorteado � �mpar.\n");
  }
 } else {
  dicasmedias(sorteado, palpite);
 }
}
