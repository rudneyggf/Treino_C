// Utiliza o marcador de posi��o '%b' para mostrar o n�mero sorteado em bin�rio

void binario(int sorteado){
  if (sorteado<0){
  sorteado*=-1;
   printf("O n�mero sorteado � '1-%b' em bin�rio.", sorteado);
  }else{
   printf("O n�mero sorteado � '0-%b' em bin�rio.", sorteado);
  }
}
