#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Aluno:Rudney Gabriel Gon�alves Fonseca
  Curso: Sistema de informa��o (Segundo Per�odo)*/

void Exercicio1(){

typedef struct Par{// struct para cria��o de pares de uma rela��o.
 int numA;
 int numB;
} Par;
printf("----------------------------------------CARDINALIDADE DO CONJUNTO-----------------------------------------\n");
int qtdElementos;
printf("\nDigite a quantidade de elementos do conjunto S\n");
scanf("%d",&qtdElementos);
int vetorElementos[qtdElementos];// vetor que armazenar� os elementos do conjunto S.
for(int i=0; i<qtdElementos;i++){// leitura do vetor
    printf("digite o elemento numero %d do vetor\n",i+1);
    scanf("%d",&vetorElementos[i]);
}
printf("\nDigite a quantidade de pares da rela��o\n");
int qtdPares;
scanf("%d",&qtdPares);
 Par vetorPares[qtdPares];// vetor que armazenar� os pares da rela��o.
for(int i=0;i<qtdPares;i++){
    printf("digite os dois numeros do par %d da rela��o\n",i+1);
    scanf("%d",&vetorPares[i].numA);
    scanf("%d",&vetorPares[i].numB);
}
int VariosUm=0;// Variavel auxiliar para determinar se a rela��o � v�rios-para-um.
int UmVarios=0;// Variavel auxiliar para determinar se a rela��o � um-para-v�rios.
for(int i=0;i<qtdPares;i++){
    for(int j=0;j<qtdPares;j++){
        if(vetorPares[i].numA==vetorPares[j].numA && i!=j)//estrutura condicional que determina se o d�minio est� relacionado com mais de um elemento.
            UmVarios=1;
        if(vetorPares[i].numB==vetorPares[j].numB && i!=j)//estrutura condicional que determina se o contradom�nio est� relacionado com mais de um elemento.
            VariosUm=1;
    }
}
if(VariosUm==0 && UmVarios==0)//Considerei a rela��o de um-para-um quando as duas vari�veis s�o 0.
    printf("Essa rela��o � de um-para-um");
if(VariosUm==1 && UmVarios==0)
    printf("Essa rela��o � de v�rios-para-um");
if(VariosUm==0 && UmVarios==1)
    printf("Essa rela��o � de um-para-v�rios");
    if(VariosUm==1 && UmVarios==1)
    printf("Essa rela��o � de v�rios-para-v�rios");//Considerei a rela��o de v�rios-para-v�rios quando as duas vari�veis s�o 1.
}

void Exercicio2(){
printf("\n------------------------REFLEXIVIDADE DA MATRIZ------------------------------\n");
printf(" Digite quantos elementos tem o conjunto S\n");
int qtdElementos;
scanf("%d",&qtdElementos);
int matriz[qtdElementos][qtdElementos];//Matriz quadrada da endorrela��o.
int reflexiva=1,irreflexiva=1;//Vari�veis que deteminar�o a reflexividade da matriz.
for(int i=0;i<qtdElementos;i++){
    for(int j=0;j<qtdElementos;j++){
            do{
              printf("digite 0 ou 1 para o elemento da linha %d coluna %d\n",i+1,j+1);
              scanf("%d",&matriz[i][j]);// leitura da matriz.
              if(matriz[i][j]!=0 && matriz[i][j]!=1){
                printf("Digite 0 ou 1 para ser uma resposta v�lida\n");
              }
            }while(matriz[i][j]!=0 && matriz[i][j]!=1);// impede o progress�o da leitura se a resposta for diferente de 0 e de 1.
        }
    }

     printf("\nMATRIZ BIN�RIA DA RELA��O\n");
    for(int i=0;i<qtdElementos;i++){
            if(matriz[i][i]==1){//estrutura condicional que determinar� se ela � irreflexiva
                irreflexiva=0;
              }
              if(matriz[i][i]==0){//estrutura condicional que determinar� se ela � reflexiva
                reflexiva=0;
              }
        for(int j=0;j<qtdElementos;j++){
              printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    if(reflexiva==1){
        printf("Esta matriz � reflexiva\n");
    }else if(irreflexiva==1){
        printf("Esta matriz � irreflexiva\n");
    }else{
        printf("A matriz n�o � nem reflexiva e nem irreflexiva");
    }
}

void Exercicio3(){
printf("\n------------------------------SIMETRIA DA MATRIZ------------------------------\n");
printf(" Digite quantos elementos tem o conjunto S\n");
int qtdElementos;
scanf("%d",&qtdElementos);
int matriz[qtdElementos][qtdElementos];//Matriz quadrada da endorrela��o
int simetrica=1,antissimetrica=1;//Vari�veis que determina��o a simetria da matriz
for(int i=0;i<qtdElementos;i++){
    for(int j=0;j<qtdElementos;j++){
            do{
              printf("digite 0 ou 1 para o elemento da linha %d coluna %d\n",i+1,j+1);
              scanf("%d",&matriz[i][j]);
              if(matriz[i][j]!=0 && matriz[i][j]!=1){// leitura da matriz.
                printf("Digite 0 ou 1 para ser uma resposta v�lida\n");
              }
            }while(matriz[i][j]!=0 && matriz[i][j]!=1);// impede o progress�o da leitura se a resposta for diferente de 0 e de 1.
        }
    }

     printf("\nMATRIZ BIN�RIA DA RELA��O\n");
    for(int i=0;i<qtdElementos;i++){
        for(int j=0;j<qtdElementos;j++){
              if(matriz[i][j]==matriz[j][i]&& i!=j){//Estrutura respons�vel por determinar se a matriz � sim�trica da matriz.
                antissimetrica=0;
              }
              if(matriz[i][j]!=matriz[j][i]){//Estrutura respons�vel por determinar se a matriz � antissim�trica.
                simetrica=0;
              }
              printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    if(simetrica==1){
        printf("Esta matriz � sim�trica\n");
    }else if(antissimetrica==1){
        printf("Esta matriz � antissim�trica\n");
    }else{
        printf("A matriz n�o � nem sim�trica e nem antissim�trica");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int exercicio=0;
    printf("Digite o n�mero da quest�o que deseja saber a resolu��o\n");
    scanf("%d",&exercicio);
    switch(exercicio){//estrutura respons�vel pela sele��o dos exerc�cios
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
            printf("O exerc�cio n�o existe ou eu n�o consegui fazer");
    }
    return 0;
}

