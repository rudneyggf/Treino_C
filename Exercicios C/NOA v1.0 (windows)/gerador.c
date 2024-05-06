int naleatorio(max) {
  int gerado, posneg;
  
  srand(time(0));
  gerado = rand()%max;
  
  posneg = rand()%2;
  
    if (posneg == 0) {
      gerado *= -1;
    }

return gerado;
}