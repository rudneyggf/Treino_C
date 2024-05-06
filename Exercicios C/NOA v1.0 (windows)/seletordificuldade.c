#define FACIL 11
#define MEDIO 34
#define DIFICIL 78
#define EXTREMO 101

int dificuldade () {

  int dif;
  
  scanf("%d", &dif);
    
    switch (dif) {
      case 1:
        return FACIL;
      break;
      case 2:
        return MEDIO;
      break;
      case 3:
        return DIFICIL;
      break;
      default:
        dificuldade();
      break;
  }
}