/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file pilhachar.h
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Biblioteca de implementação de uma pilha de char.
 * @details A biblioteca a seguir contém o arquivo com a descrição da struct e
 * das funções necessárias para alocação, liberação e diversas
 * funcionalidades de uma pilha de char.
 * @see pilhachar.c
 * 
 */

#ifndef ED_PILHACHAR_H
#define ED_PILHACHAR_H

typedef char item_char; /* MUDAR PREFIXO DE ITEM PRA MUDAR TIPO DE PILHA */


/** @brief Estrutura com os parâmetros para criação da pilha.
 *
 * @param max Determina valor maximo da pilha alocada.
 * @param top Determina onde está o topo da fila.
 * @param it Determina o vetor de itens que estará na pilha.
 */
typedef struct {
	int max;
	int top;
	item_char* it;
} Pilha_char;


/** @brief Cria a pilha de char.
 *
 * @param m Determina o tamanho do vetor de itens it, da struct Pilha_char
 * @return Um ponteiro para o início da pilha. 
 */
Pilha_char* cria_pilha_char(int m);

/** @brief Determina se a pilha está vazia.
 *
 * @param p Determina a pilha referida.
 * @return 1 Caso a pilha esteja vazia, 0 caso contrário. 
 */
int	 		pilha_vazia_char(Pilha_char *p);

/** @brief Determina se a pilha está cheia.
 *
 * @param p Determina a pilha referida.
 * @return 1 Caso a pilha esteja cheia, 0 caso contrário. 
 */
int			pilha_cheia_char(Pilha_char *p);

/** @brief Empilha um char na pilha.
 *
 * @param m Determina o char a ser empilhado.
 * @param p Determina a pilha referida.
 * @return 0 Caso a pilha esteja cheia.
 */
int 		empilhar_pilha_char(item_char m, Pilha_char *p);

/** @brief Desempilha um char da pilha.
 *
 * @param p Determina a pilha referida.
 * @return 0 Caso a pilha esteja vazia, ou o item desempilhado, caso contrário.
 */
item_char	desempilhar_pilha_char(Pilha_char *p);

/** @brief Mostra o topo da pilha.
 *
 * @param p Determina a pilha referida.
 * @return O item no topo da pilha.
 */
item_char 	topo_pilha_char(Pilha_char *p);

/** @brief Dá "free" na alocação da pilha.
 *
 * @param p Determina a pilha referida.
 */
void 		destroi_pilha_char(Pilha_char *p);
#endif