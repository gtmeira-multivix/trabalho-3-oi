#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main() {
  //Abrir arquivo de senhas para leitura:
  FILE *senhas = fopen("senhas.txt", "r");
  
  //Criar uma tabela hash:
  Hash *h = hash_criar(20011);
  
  //Enquanto não chegamos ao fim do arquivo de senhas:
  while(!feof(senhas)) {
    //Alocar uma string para armazenar a senha lida do arquivo:
    char *senha = (char*) malloc(100*sizeof(char));
    
    //Ler uma string do arquivo:
    fscanf(senhas, "%s\n", senha);
    
    //Inserir na tabela hash:
    hash_inserir(h, senha);
  }
  
  //Loop infinito esperando palavras pelo teclado:
  while(1) {
    //Ler palavra:
    printf("Digite uma senha para verificar se existe no banco de dados ou \"sair\" para encerrar o programa:\n");
    char senha[100];
    scanf("%s", senha);
    
    //Verificar se é o comando de sair:
    if(!strcmp(senha, "sair")) {
      return 0;
    }
    
    //Buscar na hash e exibir o resultado:
    if(hash_buscar(h, senha)) {
      printf("A senha %s existe no banco de dados e não é segura!\n", senha);
    } else {
      printf("A senha %s não existe no banco de dados!\n", senha);
    }
  }
}