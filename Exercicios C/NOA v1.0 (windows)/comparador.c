// Compara o tamanho do valor sorteado com o valor escolhido pelo usu�rio
// e apresenta a dica baseada no teste l�gico.

int comparaTamanho(int sorteado, int escolhido){
  if(sorteado>escolhido){
    printf("O n�mero sorteado � maior que %d.\n",escolhido);
  }else if(sorteado<escolhido){
    printf("O n�mero sorteado � menor que %d.\n",escolhido);
  }
}
