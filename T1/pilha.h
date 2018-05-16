#ifndef ED_PILHA_H
#define ED_PILHA_H

typedef char item; /* MUDAR PREFIXO DE ITEM PRA MUDAR TIPO DE PILHA */

typedef struct {
	int max;
	int top;
	item* it;
} Pilha;

Pilha* 	cria_pilha(int m);
int	 	pilha_vazia(Pilha *p);
int		pilha_cheia(Pilha *p);
int 	empilhar_pilha(item m, Pilha *p);
int 	desempilhar_pilha(Pilha *p);
int 	topo_pilha(Pilha *p);
void 	destroi_pilha(Pilha *p);
#endif