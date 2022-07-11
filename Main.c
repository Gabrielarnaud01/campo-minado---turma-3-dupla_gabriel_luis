#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//  O jogo precisa de uma inteface com as opções de ver o tempo->
//uma opção de ajuda e uma opção de revelar uma celula!!
//  O jogo tem que ter 10 linhas e 20 colunas e 40 minas!!
//  É preciso que ao final o usuario tenha um feedback de vitoria ou derota!!
//  A primeira ação sempre devera ser uma posição vazia ou com um numero, ou seja->
//a implementação das minas vem após o primeiro click  (Extra)+(ideia)!!
//  Também precisa registrar o tempo da partida (Extra)!!
//  A opção de ajuda deve indicar ao usuario uma celular com baixa chance de ter uma mina (Extra?)  !!

/*  REGRAS/INTRUÇÕES DO JOGO
1. Uma mina é revelada: nesse caso, jogo encerra com a derrota do usuário;
2. Um número é revelado: o valor indica a quantidade de minas adjacentes
considerando as 8 células ao redor de uma posição (vertical, horizontal e
diagonais);
3. Uma posição vazia é revelada: nesse caso, o jogo aplica a ação revelar sobre
todas as células adjacentes a essa posição, visto que ela não possui minas
adjacentes.
bal
*/



int main(){
    //matriz do jogo
    int **matriz;
    int *vet_rand;

    vet_rand = malloc(sizeof(int)*40);
    matriz = malloc(sizeof(int*)*10);
    srand(time(0));

    for(int i =0;i<40;i++){
      vet_rand[i] = rand() % 200 + 1;
      for(int j = 0;j<i;j++){
        if(i>0 && vet_rand[j] == vet_rand[i]){
          vet_rand[i] = rand() % 200 + 1;
          j--;
          
        }
      }
    }

    for(int i=0;i<10;i++){
        matriz[i] = malloc(sizeof(int*)*20);
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            if(i==0){
              matriz[i][j] = i+j + 1;
              for(int k=0;k<40;k++){
                if(matriz[i][j] == vet_rand[k]){
                  matriz[i][j] =4001;
                }
              }
            }
            if(i>0 && j==0){
              matriz[i][j] = i*20 +1;
              for(int k=0;k<40;k++){
                if(matriz[i][j] == vet_rand[k]){
                  matriz[i][j] =4001;
                }
              }
            }
            if(i>0 && j>0){
              matriz[i][j] = i*20 +j +1;
              for(int k=0;k<40;k++){
                if(matriz[i][j] == vet_rand[k]){
                  matriz[i][j] =4001;
                }
              }
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
          if(matriz[i][j]!=4001){
            matriz[i][j]=0;
          }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
printf("\n");
printf("\n");
    //  Podemos atribuir o valor  0 às celular que não tiverem nem numero nem bomba, atribuiremos a quantidade de bombas->
    //nas celulas adjascentes a celulas que tiverem bombas adjascentes e na celula das bombas podemos adicionar um numero maior de 40;
    //  Para a atribuição das bombas nos podemos gerar  40 numeros aleatorios entre 0-199 e colocar bombas nas posiçôes geradas!!
    //  Para a verificação de bombas ao redor como usaremos a heap//alocação precisaremos checar a casa -11,-10,-9,-1,+1,+9,+10 e +11 de cada celula->
    //e ai atribuir o numero de quantidade de bombas a essa celula!!


    return 0; 
}