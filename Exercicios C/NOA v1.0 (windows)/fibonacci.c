void fibonacci (int sorteado) {
  int f1=0,f2=1,fp=0;

  do{
    fp=f1+f2;
    f1=f2;
    f2=fp;
  }while(fp<sorteado);

  if(fp==sorteado){
    printf("O n�mero sorteado existe na Sequ�ncia de Fibonacci");
  }
  else{
    printf("O n�mero n�o existe na Sequ�ncia de Fibonacci");
  }

}
