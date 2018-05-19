/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file main.c
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Arquivo principal, o qual contém as funções de avaliação de expressão
 * e calculadora.
 * 
 * @details O arquivo a seguir contém a implementação das funções de resolução
 * de uma expressão matemática, utilizando da lógica de expressão polonesa reversa; 
 * e também a função de calculadora utilizando a lógica de stack.
 * 
 * @see pilhadouble.h
 * @see pilhachar.h
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhachar.h"
#include "pilhadouble.h"
#include "resprob.h"
#include "calculator.h"
// -------------------------------------------------------------------------
// ---------------------------MISC------------------------------------------


/** @brief Mostra na tela o menu.
 *  @details O menu possui as opções de resolução de expressão,
 *  calculadora e a opção de saída do programa.
 */
void printmenu(){
    printf("Escolha uma opcao:\n");
    printf("1.\tResolucao de expressao\n2.\tCalculadora\n3.\tSair\n\n>> ");
}
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------

int main(){
    int menusel, flagrun = 1;
    while(flagrun){    
        printmenu();
        scanf("%d", &menusel);
        switch(menusel){
            case 1:
                resprob();
                break;
            case 2:
                calc();
                break;
            case 3:
                flagrun = 0;
                break;
        }
    }
    return 0;
}