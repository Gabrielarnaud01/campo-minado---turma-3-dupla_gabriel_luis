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
    int tipo;// 3 tipos, 0. Vazio  1. Minas  2. Numero de Minas
    int n_minas;
    int pos_sequencial;
    int linha_p_ver;
    int col_p_ver;
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
              matriz[i][j].pos_sequencial = i+j + 1;
              matriz[i][j].linha_p_ver = i;
              matriz[i][j].linha_p_ver = j;
              matriz[i][j].tipo = i+j + 1;
              for(int k=0;k<40;k++){
                if(matriz[i][j].tipo == v_rand[k]){
                  matriz[i][j].tipo = 1;
                }
              }
            }
            if(i>0 && j==0){
              matriz[i][j].pos_sequencial = i*20 +1;
              matriz[i][j].linha_p_ver = i;
              matriz[i][j].linha_p_ver = j;
              matriz[i][j].tipo = i*20 +1;
              for(int k=0;k<40;k++){
                if(matriz[i][j].tipo == v_rand[k]){
                  matriz[i][j].tipo = 1;
                }
              }
            }
            if(i>0 && j>0){
              matriz[i][j].pos_sequencial = i*20 +j +1;
              matriz[i][j].linha_p_ver = i;
              matriz[i][j].linha_p_ver = j;
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

void verif_qtd_minas(espaco **matriz){
    //O tipo precisa ser o 0 pois atualmente é o tipo da celula vazia ainda sem a qtd do numero de minas.
    

      for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
          if(matriz[i][j].tipo==0){
            
            //vou verificar se tem as linhas de cima e linhas de baixa + coluna direta e coluna esquerda e fazer ifs e elses pra cada caso desses...

            if(matriz[i][j].linha_p_ver == matriz[i][j+1].linha_p_ver){
              
            }
            if(matriz[i][j].linha_p_ver == matriz[i][j-1].linha_p_ver){

            }
            if( matriz[i-1][j].linha_p_ver > 0){
              
            }
            if( matriz[i+1][j].linha_p_ver < 10){
              
            }
          }
        }
      }

    /*  Ideias de verificação junto com a parte de cima...
    if((matriz[i][j].pos_sequencial - 21)>0 && matriz[i][j].linha_p_ver==matriz[i][j].linha_p_ver && matriz[i-1][j-1].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial - 20)>0  && matriz[i-1][j].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial - 19)>0  && matriz[i-1][j+1].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial - 1)>0  && matriz[i][j].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial + 1)>200  && matriz[i][j+1].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial + 19)<200  && matriz[i+1][j-1].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial + 20)<200  && matriz[i-1][j].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }
            if((matriz[i][j].pos_sequencial + 21)<200  && matriz[i-1][j+1].tipo==1){
              matriz[i][j].n_minas += 1;
              matriz[i][j].tipo=2;
            }

    */
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
    verif_qtd_minas(matriz);

    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
          if(matriz[i][j].tipo == 1){
            printf("%d ",matriz[i][j].tipo);
          }
          if(matriz[i][j].tipo == 0){
            printf("%d ",matriz[i][j].tipo);
          }
          if(matriz[i][j].tipo == 2){
            printf("%d ",matriz[i][j].n_minas);
          }
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
