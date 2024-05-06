#include <stdio.h>
#include <stdlib.h>
#define A 4
#define C 5
#define M 6

//Rudney Gabriel Gonçalves Fonseca
//Matricula 20231SI0025
//Segundo Período

int geradorDeCongruencia( int *seed) {
    *seed = (A * (*seed) + C) % M;
    return *seed;
}

int main()
{
    int seed = 42;

    int qtdnumeros= 10;

    printf("Números pseudoaleatórios gerados:\n");

    for (int i = 0; i < qtdnumeros; ++i) {
        int numeroAleatorio = geradorDeCongruencia(&seed);
        printf("%u\n", numeroAleatorio);
    }

    return 0;



}
