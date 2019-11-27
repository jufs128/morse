#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Registro{
    char chave[6]; //Representação em código morse
    char letra[2]; //Letra ou número representado
} Registro;

typedef struct No * Apontador; //Ponteiro para o nó da esquerda ou direita

typedef struct No {
    Registro Reg; //Valores dos nós
    Apontador Esq, Dir; //Ponteiros para os nós da esquerda e da direita
} No;

void Inicializa (Apontador *Dicionario); //Cria o apontador inicial

void Pesquisa (Registro *x, Apontador p, int *i); //Identifica e retorna o nó procurado

void Insere (Registro x, Apontador *p, int *i); //Insere o nó na posição correta

void Imprime(Apontador p); //Imprime a árvore em pré-ordem
