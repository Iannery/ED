#include <stdlib.h>
#include "pilhachar.h"
#include <stdio.h>

Pilha_char* cria_pilha_char(int m){
	Pilha_char* p;

	p = (Pilha_char*) malloc(sizeof(Pilha_char));
	p -> max = m;
	p -> top = -1;
	p -> it = (item_char*) calloc(m,sizeof(item_char)); 
	return p;
}
int pilha_vazia_char(Pilha_char *p){
	if((p -> top)== -1){
		return 1;
	}
	else
		return 0;
}
int pilha_cheia_char(Pilha_char *p){
	if((p -> top) == (p -> max) - 1){
		return 1;
	}
	else
		return 0;
}
int empilhar_pilha_char(item_char m, Pilha_char *p){
	if(pilha_cheia_char(p) == 1){
		printf("pilha cheia.\n");
		abort();
	}
	(p -> top)++;
	p -> it[p -> top] = m;
}
item_char desempilhar_pilha_char(Pilha_char *p){
	item_char m;
	if(pilha_vazia_char(p) == 1){
		printf("pilha vazia.\n");
		abort();
	}
	m = p -> it[p -> top];
	(p -> top)--;
	return m;
}
item_char topo_pilha_char(Pilha_char *p){
	item_char m;
	m = p -> it[p -> top];
	return m;
}
void destroi_pilha_char(Pilha_char *p){
	free((p)->it);
	free (p);
	p = NULL;
}