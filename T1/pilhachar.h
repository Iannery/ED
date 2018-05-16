#ifndef ED_PILHACHAR_H
#define ED_PILHACHAR_H

typedef char item_char; /* MUDAR PREFIXO DE ITEM PRA MUDAR TIPO DE PILHA */

typedef struct {
	int max;
	int top;
	item_char* it;
} Pilha_char;

Pilha_char* cria_pilha_char(int m);
int	 		pilha_vazia_char(Pilha_char *p);
int			pilha_cheia_char(Pilha_char *p);
int 		empilhar_pilha_char(item_char m, Pilha_char *p);
item_char	desempilhar_pilha_char(Pilha_char *p);
item_char 	topo_pilha_char(Pilha_char *p);
void 		destroi_pilha_char(Pilha_char *p);
#endif