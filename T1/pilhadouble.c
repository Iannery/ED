#include <stdlib.h>
#include "pilhadouble.h"
#include <stdio.h>

Pilha* cria_pilha(int m){
	Pilha* p;

	p = (Pilha*) malloc(sizeof(Pilha));
	p -> max = m;
	p -> top = -1;
	p -> it = (item*) calloc(m,sizeof(item)); 
	return p;
}
int pilha_vazia(Pilha *p){
	if((p -> top)== -1){
		return 1;
	}
	else
		return 0;
}
int pilha_cheia(Pilha *p){
	if((p -> top) == (p -> max) - 1){
		return 1;
	}
	else
		return 0;
}
int empilhar_pilha(item m, Pilha *p){
	if(pilha_cheia(p) == 1){
		printf("pilha cheia.\n");
		abort();
	}
	(p -> top)++;
	p -> it[p -> top] = m;
}
item desempilhar_pilha(Pilha *p){
	item m;
	if(pilha_vazia(p) == 1){
		printf("pilha vazia.\n");
		abort();
	}
	m = p -> it[p -> top];
	(p -> top)--;
	return m;
}
double topo_pilha(Pilha *p){
	item m;
	m = p -> it[p -> top];
	return m;
}
void destroi_pilha(Pilha *p){
	free((p)->it);
	free (p);
	p = NULL;
}