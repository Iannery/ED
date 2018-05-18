/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file resprob.h
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Biblioteca de implementação da resolução de expressão.
 * @details A biblioteca a seguir contém o arquivo com a descrição das funções
 * necessárias para a resolução de uma expressão matemática.
 * @see resprob.c
 * 
 */

#ifndef ED_RESPROB_H
#define ED_RESPROB_H

/** @brief Determina a prioridade do operador em questão. 
 *  @param op Determina o operador a ser analisado.
 *  @return 2, Caso seja um operador de divisão ou multiplicação;
 *  1, aso seja um operador de soma ou subtração;
 *  0, caso contrário.
 */
int priority(char op);

/** @brief Determina se o parâmetro é um operando.
 *  @param op Determina o caractere(char) a ser analisado.
 *  @return 1, Caso seja um operando válido;
 *  0, caso contrário.
 */
int is_operand(char op);

/** @brief Determina se o parâmetro é um operador.
 *  @param op Determina o caractere(char) a ser analisado.
 *  @return 1, Caso seja um operador válido;
 *  0, caso contrário.
 */
int is_operator(char op);

/** @brief Converte o caractere do parâmetro em um inteiro.
 *  @see strtolf()
 *  @param op Determina o caractere(char) a ser analisado.
 *  @return O operando de forma inteira, ao invés de como caractere.
 */
int converter(char op);

/** @brief Transforma uma string em um número real.
 *  @details Recebe a string da função anterior, varre a string à procura
 *  de um '.' ou ','; os quais determinam que um número possui parte inteira e
 *  parte fracionária. Então, a partir deste ponto, caso exista, é começada
 *  a conversão, char por char, trabalhando com potências de 10 positivas e 
 *  negativas.
 *  @see eval_exp()
 *  @param expr Ponteiro para o início da string. 
 *  @return O número real já convertido. 
 */
double strtolf(char* expr);

/** @brief Faz a avaliação e resolução da string posfixa.
 *  @details Recebe a string da função anterior, e inicia uma pilha de números reais;
 *  Caso a parte da string até o próximo ' '(espaço) seja um operando, este
 *  é então empilhado já como número real. Caso essa parte seja um operador,
 *  dois valores da pilha são desempilhados e então ocorre a operação correspondente,
 *  empilhando o resultado na pilha. Isso ocorre até que a string posfixa acabe.
 *  @see resprob()
 *  @param expr Ponteiro para o início da string. 
 *  @return O resultado do calculo da expressão. 
 */
double eval_exp(char* expr);

/** @brief Converte a string infixa para posfixa.
 *  @details Recebe a string infixa e a string vazia posfixa da função anterior,
 *  e inicia uma pilha de caracteres.
 *  Percorre a string infixa, e caso o caractere ou parte da string seja um operando,
 *  copia o mesmo para a string posfixa. Caso seja um operador, o empiha.
 *  Caso tenha prioridade maior que algum já empilhado, desempilha o de menos prioridade
 *  e copia para a posfixa. Caso encontra um parênteses, chaves ou colchetes de abertura,
 *  o empilha. Caso encontre um de fechamento, desempilha e copia na saída até que seja
 *  desempilhado o símbolo de abertura.
 *  @see resprob()
 *  @param exp_infix Ponteiro para início da expressão infixa.
 *  @param exp_postfix Ponteiro para início da expressão posfixa. 
 */
void inf_to_postf(char* exp_infix, char* exp_postfix);

/** @brief Valida a expressão.
 *  @details Recebe a string infixa, e então checa com auxílio de uma pilha de 
 *  caracteres a quantidade de parênteses, chaves e colchetes.
 *  @param expression Ponteiro para o início da string infixa.
 *  @return 1 Caso seja válida, 0 Caso contrário.
 *   
*/
int validate_exp(char* expression);

/** @brief Função principal.
 *  @details Faz a chamada das funções validate_exp(), inf_to_postf() e
 *  eval_exp(); além de mostrar na tela ambas as expressões, infixa e posfixa,
 *  e o resultado da equação.
*/
int resprob();

#endif
