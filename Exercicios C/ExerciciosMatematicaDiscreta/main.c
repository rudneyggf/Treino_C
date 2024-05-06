#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Aluno:Rudney Gabriel Gonçalves Fonseca
  Curso: Sistema de informação (Segundo Período)*/

void Exercicio1(){

typedef struct Par{// struct para criação de pares de uma relação.
 int numA;
 int numB;
} Par;
printf("----------------------------------------CARDINALIDADE DO CONJUNTO-----------------------------------------\n");
int qtdElementos;
printf("\nDigite a quantidade de elementos do conjunto S\n");
scanf("%d",&qtdElementos);
int vetorElementos[qtdElementos];// vetor que armazenará os elementos do conjunto S.
for(int i=0; i<qtdElementos;i++){// leitura do vetor
    printf("digite o elemento numero %d do vetor\n",i+1);
    scanf("%d",&vetorElementos[i]);
}
printf("\nDigite a quantidade de pares da relação\n");
int qtdPares;
scanf("%d",&qtdPares);
 Par vetorPares[qtdPares];// vetor que armazenará os pares da relação.
for(int i=0;i<qtdPares;i++){
    printf("digite os dois numeros do par %d da relação\n",i+1);
    scanf("%d",&vetorPares[i].numA);
    scanf("%d",&vetorPares[i].numB);
}
int VariosUm=0;// Variavel auxiliar para determinar se a relação é vários-para-um.
int UmVarios=0;// Variavel auxiliar para determinar se a relação é um-para-vários.
for(int i=0;i<qtdPares;i++){
    for(int j=0;j<qtdPares;j++){
        if(vetorPares[i].numA==vetorPares[j].numA && i!=j)//estrutura condicional que determina se o dóminio está relacionado com mais de um elemento.
            UmVarios=1;
        if(vetorPares[i].numB==vetorPares[j].numB && i!=j)//estrutura condicional que determina se o contradomínio está relacionado com mais de um elemento.
            VariosUm=1;
    }
}
if(VariosUm==0 && UmVarios==0)//Considerei a relação de um-para-um quando as duas variáveis são 0.
    printf("Essa relação é de um-para-um");
if(VariosUm==1 && UmVarios==0)
    printf("Essa relação é de vários-para-um");
if(VariosUm==0 && UmVarios==1)
    printf("Essa relação é de um-para-vários");
    if(VariosUm==1 && UmVarios==1)
    printf("Essa relação é de vários-para-vários");//Considerei a relação de vários-para-vários quando as duas variáveis são 1.
}

void Exercicio2(){
printf("\n------------------------REFLEXIVIDADE DA MATRIZ------------------------------\n");
printf(" Digite quantos elementos tem o conjunto S\n");
int qtdElementos;
scanf("%d",&qtdElementos);
int matriz[qtdElementos][qtdElementos];//Matriz quadrada da endorrelação.
int reflexiva=1,irreflexiva=1;//Variáveis que deteminarão a reflexividade da matriz.
for(int i=0;i<qtdElementos;i++){
    for(int j=0;j<qtdElementos;j++){
            do{
              printf("digite 0 ou 1 para o elemento da linha %d coluna %d\n",i+1,j+1);
              scanf("%d",&matriz[i][j]);// leitura da matriz.
              if(matriz[i][j]!=0 && matriz[i][j]!=1){
                printf("Digite 0 ou 1 para ser uma resposta válida\n");
              }
            }while(matriz[i][j]!=0 && matriz[i][j]!=1);// impede o progressão da leitura se a resposta for diferente de 0 e de 1.
        }
    }

     printf("\nMATRIZ BINÁRIA DA RELAÇÃO\n");
    for(int i=0;i<qtdElementos;i++){
            if(matriz[i][i]==1){//estrutura condicional que determinará se ela é irreflexiva
                irreflexiva=0;
              }
              if(matriz[i][i]==0){//estrutura condicional que determinará se ela é reflexiva
                reflexiva=0;
              }
        for(int j=0;j<qtdElementos;j++){
              printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    if(reflexiva==1){
        printf("Esta matriz é reflexiva\n");
    }else if(irreflexiva==1){
        printf("Esta matriz é irreflexiva\n");
    }else{
        printf("A matriz não é nem reflexiva e nem irreflexiva");
    }
}

void Exercicio3(){
printf("\n------------------------------SIMETRIA DA MATRIZ------------------------------\n");
printf(" Digite quantos elementos tem o conjunto S\n");
int qtdElementos;
scanf("%d",&qtdElementos);
int matriz[qtdElementos][qtdElementos];//Matriz quadrada da endorrelação
int simetrica=1,antissimetrica=1;//Variáveis que determinação a simetria da matriz
for(int i=0;i<qtdElementos;i++){
    for(int j=0;j<qtdElementos;j++){
            do{
              printf("digite 0 ou 1 para o elemento da linha %d coluna %d\n",i+1,j+1);
              scanf("%d",&matriz[i][j]);
              if(matriz[i][j]!=0 && matriz[i][j]!=1){// leitura da matriz.
                printf("Digite 0 ou 1 para ser uma resposta válida\n");
              }
            }while(matriz[i][j]!=0 && matriz[i][j]!=1);// impede o progressão da leitura se a resposta for diferente de 0 e de 1.
        }
    }

     printf("\nMATRIZ BINÁRIA DA RELAÇÃO\n");
    for(int i=0;i<qtdElementos;i++){
        for(int j=0;j<qtdElementos;j++){
              if(matriz[i][j]==matriz[j][i]&& i!=j){//Estrutura responsável por determinar se a matriz é simétrica da matriz.
                antissimetrica=0;
              }
              if(matriz[i][j]!=matriz[j][i]){//Estrutura responsável por determinar se a matriz é antissimétrica.
                simetrica=0;
              }
              printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    if(simetrica==1){
        printf("Esta matriz é simétrica\n");
    }else if(antissimetrica==1){
        printf("Esta matriz é antissimétrica\n");
    }else{
        printf("A matriz não é nem simétrica e nem antissimétrica");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int exercicio=0;
    printf("Digite o número da questão que deseja saber a resolução\n");
    scanf("%d",&exercicio);
    switch(exercicio){//estrutura responsável pela seleção dos exercícios
        case 1:
            Exercicio1();
            break;
        case 2:
            Exercicio2();
            break;
        case 3:
            Exercicio3();
            break;
        default:
            printf("O exercício não existe ou eu não consegui fazer");
    }
    return 0;
}

