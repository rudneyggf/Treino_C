/* Calcula o resto da divis�o por 10 do n�mero sorteado, que coincide com o valor do �ltimo digito
   do n�mero. */

  void ultimoDigito(int sorteado, int palpite){
  if (sorteado >= 10) {
    int digito=sorteado%10;
    if(sorteado<0){
      digito*=-1;
    }
  printf("O �ltimo digito do n�mero sorteado � '%d'.\n",digito); }
    else {
      dicasmedias(sorteado, palpite);
    }
}
