void somaproduto(int sorteado){
  int d1=0,d2=0;
  sorteado= abs(sorteado);

  d1 = sorteado/10;
  d2 = sorteado%10;


  printf("\nConsiderando o valor absoluto, a soma dos d�gitos do n�mero sorteado �: %d ",d1+d2);
  printf("\nConsiderando o valor absoluto, o produto do d�gitos do n�mero sorteado �: %d",d1*d2);
}
