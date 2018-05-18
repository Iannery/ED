/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file pilhadouble.h
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Biblioteca de implementação de uma pilha de double.
 * @details A biblioteca a seguir contém o arquivo com a descrição da struct e
 * das funções necessárias para alocação, liberação e diversas
 * funcionalidades de uma pilha de double.
 * @see pilhadouble.c
 * 
 */

#ifndef ED_PILHAD_H
#define ED_PILHAD_H


typedef double item;


/** @brief Estrutura com os parâmetros para criação da pilha.
 *
 * @param max Determina valor maximo da pilha alocada.
 * @param top Determina onde está o topo da fila.
 * @param it Determina o vetor de itens que estará na pilha.
 */
typedef struct {
	int max;
	int top;
	item* it;
} Pilha;


/** @brief Cria a pilha de double.
 *
 * @param m Determina o tamanho do vetor de itens it, da struct Pilha_char
 * @return Um ponteiro para o início da pilha. 
 */
Pilha* 	cria_pilha(int m);

/** @brief Determina se a pilha está vazia.
 *
 * @param p Determina a pilha referida.
 * @return 1 Caso a pilha esteja vazia, 0 caso contrário. 
 */
int	 	pilha_vazia(Pilha *p);

/** @brief Determina se a pilha está cheia.
 *
 * @param p Determina a pilha referida.
 * @return 1 Caso a pilha esteja cheia, 0 caso contrário. 
 */
int		pilha_cheia(Pilha *p);

/** @brief Empilha um número real na pilha.
 *
 * @param m Determina o número a ser empilhado.
 * @param p Determina a pilha referida.
 * @return 0 Caso a pilha esteja cheia.
 */
int 	empilhar_pilha(item m, Pilha *p);

/** @brief Desempilha um número real da pilha.
 *
 * @param p Determina a pilha referida.
 * @return 0 Caso a pilha esteja vazia, ou o item desempilhado, caso contrário.
 */
item 	desempilhar_pilha(Pilha *p);

/** @brief Mostra o topo da pilha.
 *
 * @param p Determina a pilha referida.
 * @return O item no topo da pilha.
 */
item 	topo_pilha(Pilha *p);

/** @brief Mostra na tela todo o conteúdo da pilha.
 *
 * @param p Determina a pilha referida.
 */
void	mostra_pilha(Pilha *p);

/** @brief Dá "free" na alocação da pilha.
 *
 * @param p Determina a pilha referida.
 */
void 	destroi_pilha(Pilha *p);
#endif