#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//  O jogo precisa de uma inteface com as opções de ver o tempo->
// uma opção de ajuda e uma opção de revelar uma celula!!
//  O jogo tem que ter 10 linhas e 20 colunas e 40 minas!!
//  É preciso que ao final o usuario tenha um feedback de vitoria ou derota!!
//  A primeira ação sempre devera ser uma posição vazia ou com um numero, ou
//  seja->
// a implementação das minas vem após o primeiro click  (Extra)+(ideia)!!
//  Também precisa registrar o tempo da partida (Extra)!!
//  A opção de ajuda deve indicar ao usuario uma celular com baixa chance de ter
//  uma mina (Extra?)  !!

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

typedef struct {
  int tipo; 
  int n_minas;
  int pos_sequencial;
  char status;


} espaco;

void v_minas(int *v_rand) {
  char ja_consta;
  srand(time(NULL));
  for (int i = 0; i < 40; i++) {
    v_rand[i] = rand() % 200;
    ja_consta = 'N';
    for (int j = 0; j < i && ja_consta == 'N'; j++) {
      if (v_rand[i] == v_rand[j])
        ja_consta = 'S';
    }
    if (ja_consta == 'S')
      i--;
  }
}

void cria_campo(int *v_rand, espaco **matriz) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      matriz[i][j].tipo = 4;
      matriz[i][j].n_minas = 0;
      matriz[i][j].status = '*';
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      matriz[i][j].pos_sequencial = i * 20 + j;
      for (int k = 0; k < 40; k++) {
        if (matriz[i][j].pos_sequencial == v_rand[k]) {
          matriz[i][j].tipo = 1;
        }
      }
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
          if (matriz[i][j].tipo != 1) {
            matriz[i][j].tipo = 0;
          }
        }
      }
    }
  }
}

void verif_mina_pontas(espaco **matriz) {

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      switch (matriz[i][j].pos_sequencial) {
      case 0:
        if (matriz[i][j].tipo == 1) {
            break;
        } else {
          if (matriz[0][1].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[1][0].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[1][1].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          break;
        }

      case 19:
        if (matriz[i][j].tipo == 1) {
          break;
        } else {
          if (matriz[0][18].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[1][19].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[1][18].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          break;
        }

      case 180:
        if (matriz[i][j].tipo == 1) {
          break;
        } else {
          if (matriz[8][0].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[9][1].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[8][1].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          break;
        }

      case 199:
        if (matriz[i][j].tipo == 1) {
          break;
        } else {
          if (matriz[9][18].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[8][19].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          if (matriz[8][18].tipo == 1) {
            matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
          }
          break;
        }
      }
    }
  }
}

void verif_mina_extremoz_linhas(espaco **matriz){
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      if (matriz[i][j].tipo == 1) {
        continue;
      }
      if(matriz[i][j].pos_sequencial>0 && matriz[i][j].pos_sequencial<19){
        if(matriz[i][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i+1][j].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i+1][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i+1][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
      }
      if(matriz[i][j].pos_sequencial>180 && matriz[i][j].pos_sequencial<199){
        if(matriz[i][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
      }
      if(i>0 && i<9 && j==0){
        if(matriz[i+1][j].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i+1][j+1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
      }
      if(i>0 && i<9 && j==19){
        if(matriz[i+1][j].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i-1][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
        if(matriz[i+1][j-1].tipo == 1) {
          matriz[i][j].n_minas = matriz[i][j].n_minas+ 1;
        }
      }
    }
  }
}
void verif_mina_centro(espaco **matriz){
   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      if (matriz[i][j].tipo == 1) {
        continue;
      }
      if(1 && i>0 && j>0 && i<9 && j<19){
        if(matriz[i][j-1].tipo == 1){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i][j+1].tipo == 1 ){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i-1][j].tipo == 1){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i+1][j].tipo == 1 ){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i+1][j-1].tipo == 1 ){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i+1][j+1].tipo == 1 ){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i-1][j-1].tipo == 1 ){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
        if(matriz[i-1][j+1].tipo == 1 ){
          matriz[i][j].n_minas = matriz[i][j].n_minas + 1;
        }
      }
    }
  }
}


void cria_camp_min(int *vet_rand, espaco **matriz){
  v_minas(vet_rand);
  cria_campo(vet_rand,matriz);
  verif_mina_pontas(matriz);
  verif_mina_extremoz_linhas(matriz);
  verif_mina_centro(matriz);
}

int main() {
  // matriz do jogo
  espaco **matriz;
  int *vet_rand;
  char selecionado[255];
  int linha,coluna;
  int aux = 0;
  int contador = 0;

  vet_rand = malloc(sizeof(int) * 40);

  matriz = malloc(sizeof(espaco *) * 10);
  for (int i = 0; i < 10; i++) {
    matriz[i] = malloc(sizeof(espaco) * 20);
  }

  cria_camp_min(vet_rand, matriz);
  free(vet_rand);
  // func para checar numero de bombas.
  // verif_qtd_minas(matriz);
  printf("              MENU\n  Jogar\n  Jogar-Automaticamente\n  Instrucoes\nDigte uma das opções acima:\n  ");
  scanf("%s",selecionado);
  if(strcmp(selecionado,"Instrucoes")==0){
    printf(" 1. Uma mina é revelada: nesse caso, o jogo encerra com a derrota do usuário;\n 2. Um número é revelado: o valor indica a quantidade de minas adjacentes considerando as 8 células ao redor de uma posição (vertical, horizontal e diagonais);\n 3. Uma posição vazia é revelada: nesse caso, o jogo aplica a ação revelar sobre todas as células adjacentes a essa posição, visto que ela não possui minas adjacentes.");
  }
  if(strcmp(selecionado,"Jogar")==0){
    //criar jogo
    for(int i = 0; i<10; i++){
      for(int j = 0; j<20; j++){
        printf("%c ", matriz[i][j].status);
      }
    printf("\n");
    }

    while(aux == 0 || contador < 160){
      scanf("%d",  &linha);
      scanf("%d",  &coluna);
      contador++;

      if(matriz[linha][coluna].tipo == 0 && matriz[linha][coluna].n_minas == 0){
        if(linha == 0 && coluna == 0){
          matriz[linha][coluna].status = matriz[linha][coluna].n_minas + '0';
          matriz[linha][coluna+1].status = matriz[linha][coluna+1].n_minas + '0';
          matriz[linha+1][coluna].status = matriz[linha+1][coluna].n_minas + '0';
          matriz[linha+1][coluna+1].status = matriz[linha+1][coluna+1].n_minas + '0';
        }
        else if(linha > 0 && coluna == 0){
          matriz[linha][coluna].status = matriz[linha][coluna].n_minas + '0';
          matriz[linha-1][coluna].status = matriz[linha-1][coluna].n_minas + '0';
          matriz[linha+1][coluna].status = matriz[linha+1][coluna].n_minas + '0';
          matriz[linha][coluna+1].status = matriz[linha][coluna+1].n_minas + '0';
          matriz[linha+1][coluna+1].status = matriz[linha+1][coluna+1].n_minas + '0';
          matriz[linha-1][coluna+1].status = matriz[linha-1][coluna+1].n_minas + '0';
        }
        else if(linha == 0 && coluna > 0){
          matriz[linha][coluna].status = matriz[linha][coluna].n_minas + '0';
          matriz[linha+1][coluna].status = matriz[linha+1][coluna].n_minas + '0';
          matriz[linha][coluna+1].status = matriz[linha][coluna+1].n_minas + '0';
          matriz[linha][coluna-1].status = matriz[linha][coluna-1].n_minas + '0';
          matriz[linha+1][coluna+1].status = matriz[linha+1][coluna+1].n_minas + '0';
          matriz[linha+1][coluna-1].status = matriz[linha+1][coluna-1].n_minas + '0';
        }
        else{
          matriz[linha][coluna].status = matriz[linha][coluna].n_minas + '0';
          matriz[linha+1][coluna].status = matriz[linha+1][coluna].n_minas + '0';
          matriz[linha-1][coluna].status = matriz[linha-1][coluna].n_minas + '0';
          matriz[linha][coluna+1].status = matriz[linha][coluna+1].n_minas + '0';
          matriz[linha][coluna-1].status = matriz[linha][coluna-1].n_minas + '0';
          matriz[linha+1][coluna+1].status = matriz[linha+1][coluna+1].n_minas + '0';
          matriz[linha+1][coluna-1].status = matriz[linha+1][coluna-1].n_minas + '0';
          matriz[linha-1][coluna+1].status = matriz[linha-1][coluna+1].n_minas + '0';
          matriz[linha-1][coluna-1].status = matriz[linha-1][coluna-1].n_minas + '0';
        }
      }
      else if(matriz[linha][coluna].tipo == 1){
        printf("PERDEU\n");
        break;
      }
      else{
        matriz[linha][coluna].status = matriz[linha][coluna].n_minas + '0';
      }
      for(int i = 0; i<10; i++){
        for(int j = 0; j<20; j++){
          printf("%c ", matriz[i][j].status);
        }
      printf("\n");
      }
  }
  }
  if(strcmp(selecionado,"Jogar-Automaticamente")==0){
    //criar jogo automatico
  }

  for (int i = 0; i < 10; i++) {
    free(matriz[i]);
  }
  free(matriz);
    
  return 0;
}
