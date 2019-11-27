# morse
  O programa recebe um texto em morse e retorna sua tradução. Adicionado o parâmetro -a na execução, imprime o alfabeto em morse.
  
## Implementação
  O tradutor de morse foi implementado utilizando uma árvora binária em que cada nó representa um caractere. Se o próximo símbolo for ".", vai para a esquerda, se for "-" vai para a direita.
  
## Entrada
  O programa lê linha por linha, portanto a separação de mensagens na entrada resulta na separação de tais mensagens na saída.
  Cada caractere deve estar separado por um espaço, e o carater "/" marca o fim das palavras e dá um espaço na saída.
  
#### Entrada: 

   ... . -. / .--. . -- ..-. - ..-. ... / .--. .-. ..-. / ... . -- .. ..- .-.

   .. -. / .-. . ..- --. --- / - . / ..- ... --- .-.. ..-. -. . --. -.. ---
   
#### Saída:
   SEM PEGADAS PRA SEGUIR
   
   UM REINO DE ISOLAMENTO

## Compilação
  Mantendo-se morse.txt, arvore.h, arvore.c e main.c no mesmo diretório, abrindo o prompt de comando e acessando-o, deve-se compilar utilizando o seguinte comando:


gcc -o nomedoprograma arvore.c main.c


## Execução


  O programa está preparado para receber dados pela entrada padrão (stdin), então, deve-se executar em uma das seguintes maneiras:


./nomedoprograma , para inserir os comandos manualmente.

./nomedoprograma < arq.in > arq.out , para utilizar um arquivo como entrada e saída.
	
  
  Caso deseje-se imprimir a árvore em pré-ordem, deve-se adicionar o parâmetro -a à execução, como a seguir:

./nomedoprograma -a < arq.in > arq.out
