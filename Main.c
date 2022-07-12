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

typedef struct{
    int tipo;// 3 tipos, 1. vazio  2. numero de minas  3. Mina
    int n_minas;
}espaco;


void cria_campo(int *v_rand, espaco **matriz){
     for(int i =0;i<40;i++){
      v_rand[i] = rand() % 200 + 1;
      for(int j = 0;j<i;j++){
        if(i>0 && v_rand[j] == v_rand[i]){
          v_rand[i] = rand() % 200 + 1;
          j--;
        }
      }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            if(i==0){
              matriz[i][j].tipo = i+j + 1;
              for(int k=0;k<40;k++){
                if(matriz[i][j].tipo == v_rand[k]){
                  matriz[i][j].tipo = 1;
                }
              }
            }
            if(i>0 && j==0){
              matriz[i][j].tipo = i*20 +1;
              for(int k=0;k<40;k++){
                if(matriz[i][j].tipo == v_rand[k]){
                  matriz[i][j].tipo = 1;
                }
              }
            }
            if(i>0 && j>0){
              matriz[i][j].tipo = i*20 +j +1;
              for(int k=0;k<40;k++){
                if(matriz[i][j].tipo == v_rand[k]){
                  matriz[i][j].tipo = 1;
                }
              }
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
          if(matriz[i][j].tipo!=1){
            matriz[i][j].tipo = 0;
          }
        }
    }
}


int main(){
    //matriz do jogo
    espaco **matriz;
    int *vet_rand;

    vet_rand = malloc(sizeof(int)*40);
    matriz = malloc(sizeof(espaco*)*10);
    srand(time(0));

    for(int i=0;i<10;i++){
        matriz[i] = malloc(sizeof(espaco*)*20);
    }
    cria_campo(vet_rand,matriz);
    // func para checar numero de bombas.


    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            printf("%d ",matriz[i][j].tipo);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");


    for(int i=0;i<10;i++){
        free(matriz[i]);
    }
    free(matriz);
    free(vet_rand);
/*
    Podemos atribuir o valor  0 às celular que não tiverem nem numero nem bomba, atribuiremos a quantidade de bomba nas celulas adjascentes 
    e na celula das bombas podemos adicionar um numero maior de 40;

    Para a atribuição das bombas nos podemos gerar  40 numeros aleatorios entre 0-199 e colocar bombas nas posiçôes geradas!!

    Para a verificação de bombas ao redor como usaremos a heap//alocação precisaremos checar a casa -11,-10,-9,-1,+1,+9,+10 e +11 
    de cada celula e ai atribuir o numero de quantidade de bombas a essa celula!!

*/
    return 0; 
}
