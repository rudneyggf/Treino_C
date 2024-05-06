// Utiliza o marcador de posição '%b' para mostrar o número sorteado em binário

void binario(int sorteado){
  if (sorteado<0){
  sorteado*=-1;
   printf("O número sorteado é '1-%b' em binário.", sorteado);
  }else{
   printf("O número sorteado é '0-%b' em binário.", sorteado);
  }
}
