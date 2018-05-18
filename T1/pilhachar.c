/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file pilhachar.c
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Arquivo de implementação de uma pilha de char.
 * @details O arquivo a seguir contém a implementação
 * das funções necessárias para alocação, liberação e diversas
 * funcionalidades de uma pilha de char.
 * @see pilhachar.h
 * 
 */

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
		return 0;
	}
	(p -> top)++;
	p -> it[p -> top] = m;
}
item_char desempilhar_pilha_char(Pilha_char *p){
	item_char m;
	if(pilha_vazia_char(p) == 1){
		printf("pilha vazia.\n");
		return 0;
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