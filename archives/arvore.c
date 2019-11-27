#include "arvore.h"

void Inicializa (Apontador *Arvore){ //Cria o primeiro apontador
    *Arvore = NULL; //Primeiro nó; começa com apontador null
}

void Pesquisa (Registro *x, Apontador p, int *i){ //Procura o elemento na árvore
    if (p == NULL) //Se chegar a um nó(ponteiro) null, elemento não está na árvore
        printf("Registro nao esta presente\n");
    else if (x->chave[*i] == '.') { //Se o char na posição sendo avaliada é ".", vai para esquerda
        (*i)++; //Aumenta 1 para que o próximo char da string seja avaliado
        Pesquisa(x, p->Esq, i); //Desloca para a esquerda
    } else if (x->chave[*i] == '-') { //Se o char na posição sendo avaliada é "-", vai para direita
        (*i)++; //Aumenta 1 para que o próximo char da string seja avaliado
        Pesquisa(x, p->Dir, i); //Desloca para a direita
    } else{ //Acabou a string; chegou à posição
        if(strlen(p->Reg.letra) > 0) //Checa se há um valor válido no ponteiro
            *x = p->Reg; //Copia o registro da posição para o ponteiro de registro passado
        else
            printf("Registro nao esta presente\n");
    }
}

void Insere (Registro x, Apontador *p, int *i){ //Insere elemento na árvore
    if (*p == NULL)  { //Se chegar a um campo null, cria o nó
        *p = (Apontador) malloc(sizeof(No)); //Aloca espaço na memória
        (*p)->Esq = NULL;
        (*p)->Dir = NULL; //Nó à esquerda e à direita inicialmente null
    }

    if (x.chave[*i] == '.'){ //Verifica se o char sendo verificado é '.', se sim para o nó da esquerda
        (*i)++; //Adiciona 1 para verificar o próximo char
        Insere(x, &(*p)->Esq, i); //Desloca para a esquerda
    } else if (x.chave[*i] == '-'){ //Verifica se o char sendo verificado é '-', se sim para o nó da direita
        (*i)++; //Adiciona 1 para verificar o próximo char
        Insere(x, &(*p)->Dir, i); //Desloca para a direita
    } else{ //Fim da string chave; inserir o registro na posição
        strcpy((*p)->Reg.letra, x.letra); //Copia a letra ou número representado
        strcpy((*p)->Reg.chave, x.chave); //Copia a representação em morse
    }
}

void Imprime(Apontador p){ //Imprime a árvore
    if(p == NULL) //Se ponteiro null, não imprime nada, volta
        return;

    if(strlen(p->Reg.letra) > 0) //Verifica se há conteúdo no registro apontado
        printf("%s %s\n", p->Reg.letra,p->Reg.chave); //Se sim, imprime

    Imprime(p->Esq); //Desloca para a esquerda
    Imprime(p->Dir); //Desloca para a direita
}
