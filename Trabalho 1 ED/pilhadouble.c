/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file pilhadouble.c
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Arquivo de implementação de uma pilha de double.
 * @details O arquivo a seguir contém a implementação
 * das funções necessárias para alocação, liberação e diversas
 * funcionalidades de uma pilha de double.
 * @see pilhadouble.h
 * 
 */

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
		return 0;
	}
	(p -> top)++;
	p -> it[p -> top] = m;
}
item desempilhar_pilha(Pilha *p){
	item m;
	if(pilha_vazia(p) == 1){
		printf("pilha vazia.\n");
		return 0;
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
void mostra_pilha(Pilha *p){
	if(pilha_vazia(p) == 1){
		printf("pilha vazia. \n");
	}
	else{
		for(int i = 0; i <= p -> top; i++){
			printf("%d. %lf\n", p->top - i + 1, p->it[i]);
		}
	}
}
void destroi_pilha(Pilha *p){
	free((p)->it);
	free (p);
	p = NULL;
}