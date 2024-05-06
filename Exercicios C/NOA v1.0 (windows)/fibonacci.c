void fibonacci (int sorteado) {
  int f1=0,f2=1,fp=0;

  do{
    fp=f1+f2;
    f1=f2;
    f2=fp;
  }while(fp<sorteado);

  if(fp==sorteado){
    printf("O número sorteado existe na Sequência de Fibonacci");
  }
  else{
    printf("O número não existe na Sequência de Fibonacci");
  }

}
