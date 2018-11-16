#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct _hash {
  char **tabela;
  int tamanho;
};

/**
 * Cria uma tabela hash vazia, com uma tabela do tamanho indicado.
 * É recomendável que o tamanho seja um número primo.
 */
Hash* hash_criar(int tamanho) {
  Hash *h = (Hash*) malloc(sizeof(Hash));
  h->tabela = (char**) malloc(tamanho*sizeof(char*));
  h->tamanho = tamanho;
  
  //Memset seta todas as posições de memória em um intervalo para um determinado valor.
  //Aqui, estamos escolhendo esse valor como 0, o que efetivamente faz com que todas as
  //linhas da tabela apontem para NULL:
  memset(h->tabela, 0, tamanho*sizeof(char*));
  
  return h;
}

/**
 * Dada uma string, o tamanho da tabela hash e o número de colisões geradas até o momento
 * para esta palavra, esta função calcula a nova posição onde tentaremos inserir a palavra.
 * Para este exercício, o hash é calculado da seguinte maneira:
 * Primeiro, some o valor de todos os caracteres da palavra.
 * Depois, some o valor de i a esse total.
 * Por fim, calcule o valor de total%tamanhoHash e retorne.
 * A função strlen pode ser útil para calcular o número de caracteres da string.
 */
int funcao_hash(char *palavra, int tamanhoHash, int i) {
  //Implemente
}

/**
 * Insere uma palavra na tabela hash.
 * Deve-se começar chamando a função hash com i=0. Se houver colisão, chame novamente a
 * função hash com i=1. Repita o procedimento até encontrar uma posição livre ou i
 * ser igual ao tamanho da hash (tabela cheia).
 */
void hash_inserir(Hash *h, char *palavra) {
  //Implemente
}

/**
 * Verifica se uma palavra está presente na hash. Deve retornar 1 se a palavra for encontrada
 * e 0 caso contrário.
 * Comece chamando a função hash com i=0 e verifique se existe uma palavra na posição calculada
 * e se a palavra é igual à palavra buscada. Se for igual, retorne 1, caso contrário, continue
 * o processo de chamar a função hash com valores crescentes de i até encontrar a palavra procurada,
 * chegar em uma posição vazia ou o valor de i se tornar igual ao tamanho da hash.
 * A função strcmp pode ser útil para comparar duas strings. Ela retorna zero quando duas strings são iguais.
 */
int hash_buscar(Hash *h, char *palavra) {
  //Implemente
}

/**
 * Libera a memória ocupada pela hash.
 */
void hash_destruir(Hash *h) {
  int i;
  for(i = 0; i < h->tamanho; i++) {
    if(h->tabela[i] != NULL) {
      free(h->tabela[i]);
    }
  }
  
  free(h->tabela);
  free(h);
}