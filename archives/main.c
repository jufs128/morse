#include "arvore.h"

void LeArquivo(Apontador *inicio){ //Lê o arquivo morse.txt e popula a árvore
    Registro x; //Registro que receberá os valores
    int i = 0; //Utilizado no Insere
    char aux; //Recebe a letra ou número e passa para x.letra, que é string

    FILE *arq; //Ponteiro de arquivo
    arq = fopen("morse.txt","r"); //Abre e lê morse.txt

    while(!feof(arq)){ //Enquanto o arquivo não acaba
        fscanf(arq,"%s %s",&aux,x.chave); //Lê o elemento representado e sua forma em morse
        x.letra[0] = aux; //Primeiro elemento da string letra é o aux
        Insere(x,&(*inicio),&i); //Insere na x árvore
        i = 0; //Zera para o próximo Insere
    }

    fclose(arq);
}

int main (int argc, char *argv[]){
    Apontador inicio; //Ponteiro para o nó inicial da árvore
    Registro x;
    Inicializa(&inicio); //Inicializa o primeiro nó
    int i = 0; //Utilizado em Pesquisa
    char linha[1000]; //Lê a linha e recebe substring(código morse)

    LeArquivo(&inicio); //Lê morse.txt e popula a árvore

    //Leitura da entrada
    while((fgets(linha,1000,stdin)) != NULL){ //Enquanto tiverem linhas
        int tam = strlen(linha); //Obtém tamanho da string da linha
        for(int j = 0; j < tam; j++){ //Enquanto não tiver passado por toda a linha
            if(j == 0) //Se for a primeira palavra da linha
                strcpy(x.chave,strtok(linha," ")); //Obtém até o espaço
            else //Se ão for a primeira
                strcpy(x.chave,strtok(NULL," ")); //Obtém até o espaço
            j = j + strlen(x.chave); //Adiciona o tamanho da string à j
            if(strcmp(x.chave,"/") == 0){ //Verifica se a string é barra
                printf(" "); //Se sim, espaço
            } else{ //Senão, procura pelo código na árvore
                Pesquisa(&x,inicio,&i);
                printf("%s",x.letra); //Imprime o que representa
            }
            i = 0; //Zera i para as próximas pesquisas
        }
        printf("\n"); //Próxima linha
        fflush(stdin); //Limpa a entrada
    }

    //Leitura dos parâmetros
    if (argc > 1) {
        if(strcmp(argv[1],"-a") == 0){ //Verifica se o primeiro parâmetro é -a
            printf("\n");
            Imprime(inicio); //Se sim, imprime a árvore
        }
    }

    return 0;
}
