#ifndef _HASH_H
#define _HASH_H

typedef struct _hash Hash;

Hash* hash_criar(int tamanho);
void hash_inserir(Hash *h, char *palavra);
int hash_buscar(Hash *h, char *palavra);
void hash_destruir();

#endif