/* Calcula o resto da divisão por 10 do número sorteado, que coincide com o valor do último digito
   do número. */

  void ultimoDigito(int sorteado, int palpite){
  if (sorteado >= 10) {
    int digito=sorteado%10;
    if(sorteado<0){
      digito*=-1;
    }
  printf("O último digito do número sorteado é '%d'.\n",digito); }
    else {
      dicasmedias(sorteado, palpite);
    }
}
