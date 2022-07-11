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
*/