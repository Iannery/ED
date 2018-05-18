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

void exclamationcalc(char op, Pilha* p);

void normalcalc(char op, Pilha* p);

void calc();

#endif