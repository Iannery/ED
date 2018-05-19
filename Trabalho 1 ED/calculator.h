/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file calculator.h
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Biblioteca de implementação da calculadora.
 * @details A biblioteca a seguir contém o arquivo com a descrição das funções
 * necessárias para o funcionamento da calculadora.
 * @see calculator.c
 * 
 */

#ifndef ED_CALCULATOR_H
#define ED_CALCULATOR_H


/** @brief Determina se o parâmetro é um operador.
 *  @param op Determina o caractere(char) a ser analisado.
 *  @return 1, Caso seja um operador válido;
 *  0, caso contrário.
 */
int is_operatorcalc(char op);

/** @brief Mostra na tela as instruções do modo calculadora.
 *  @details A função avisa sobre a necessidade da leitura do README para
 *  utilização da ferramenta calculadora, e mostra o comando de saída da mesma.
 */
void printcalcinstr();

/** @brief Converte o caractere do parâmetro em um inteiro.
 *  @see strtolfcalc()
 *  @param op Determina o caractere(char) a ser analisado.
 *  @return O operando de forma inteira, ao invés de como caractere.
 */
int convertercalc(char op);

/** @brief Transforma uma string em um número real.
 *  @details Recebe a string da função anterior, varre a string à procura
 *  de um '.' ou ','; os quais determinam que um número possui parte inteira e
 *  parte fracionária. Então, a partir deste ponto, caso exista, é começada
 *  a conversão, char por char, trabalhando com potências de 10 positivas e 
 *  negativas.
 *  @see calc()
 *  @param expr Ponteiro para o início da string. 
 *  @return O número real já convertido. 
 */
double strtolfcalc(char* expr);

/** @brief Rotina de tratamento caso seja feito uso do operador '!'
 *  @details Recebe o operador que antecede '!' e a pilha da calculadora; e então
 *  faz a operação respectiva ao operador, até que sobre somente um elemento na pilha.
 *  @see calc()
 *  @param op Caractere do operador, para distinguir a operação feita. 
 *  @param p Ponteiro para o início da pilha da calculadora.
 */
void exclamationcalc(char op, Pilha* p);

/** @brief Rotina de tratamento para caso seja operação normal.
 *  @details Recebe o operador, a pilha da calculadora, desempilha dois elementos da
 *  pilha, faz a operação e empilha o valor resultado da operação.
 *  @see calc()
 *  @param op Caractere do operador, para distinguir a operação feita. 
 *  @param p Ponteiro para o início da pilha da calculadora.
 */
void normalcalc(char op, Pilha* p);

/** @brief Calculadora efetiva.
 *  @details Recebe, em loop, uma string. Caso seja operando, empilha na pilha.
 *  Caso seja operador, vai para a respectiva função. Caso seja 'c', empilha o valor
 *  n, m vezes na pilha, sendo n o penúltimo número da pilha e m o último número.
 *  Após isso, mostra a pilha inteira na tela. Caso seja digitado "exit", sai do
 *  programa.
 */
void calc();

#endif