#include <stdio.h>
#include <stdlib.h>
#define A 4
#define C 5
#define M 6

//Rudney Gabriel Gon�alves Fonseca
//Matricula 20231SI0025
//Segundo Per�odo

int geradorDeCongruencia( int *seed) {
    *seed = (A * (*seed) + C) % M;
    return *seed;
}

int main()
{
    int seed = 42;

    int qtdnumeros= 10;

    printf("N�meros pseudoaleat�rios gerados:\n");

    for (int i = 0; i < qtdnumeros; ++i) {
        int numeroAleatorio = geradorDeCongruencia(&seed);
        printf("%u\n", numeroAleatorio);
    }

    return 0;



}
