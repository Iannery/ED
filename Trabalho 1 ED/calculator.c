/*#####################################################
  # UNIVERSIDADE DE BRASILIA                          #
  # MATERIA: ED - 116319                              #
  # Ian Nery Bandeira - 17/0144739                    #
  # gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
  # SO - Ubuntu 18.04                                 #
  # Compilado no terminal / Editado em VS Code        #
  ##################################################### */

/**
 * @file calculator.c
 * @author Ian Nery Bandeira
 * @date 18 May 2018
 * @brief Arquivo de implementação da função calculadora.
 * @details O arquivo contém a implementação das funções necessárias para o
 * funcionamento correto da calculadora.
 * @see calculator.h
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhachar.h"
#include "pilhadouble.h"
#include "calculator.h"


int convertercalc(char op){
    switch(op){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
}
double strtolfcalc(char* expr){
    int i, m = 0, j, auxconv, tamstr;
    double tot;
    tamstr = strlen(expr);
    for(i = 0; i < tamstr; i++){
        if(expr[i] == '.' || expr[i] == ','){
            m = i;
        }
    }
    if(m){
        for(i = (m - 1), j = 0; j < m; i--, j++){
            auxconv = convertercalc(expr[j]);
            tot += auxconv * pow(10, i);
        }
        for(i = 0, j = m + 1; j < tamstr; i++, j++){
            auxconv = convertercalc(expr[j]);
            tot += auxconv / pow(10, i + 1);
        }
    }
    else{
        for(i = (tamstr - 1), j = 0; j < tamstr; i--, j++){
            auxconv = convertercalc(expr[j]);
            tot += auxconv * pow(10, i);
        }
    }
    return tot;
}

int is_operatorcalc(char op){
    if(op == '*' || op == '/' || op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

void printcalcinstr(){
    printf("Digite os operadores e operandos como especificado no README.txt.\n");
    printf("Para sair, digite 'exit'. \n");
}
//--------------------------------------------------------------------------

void exclamationcalc(char op, Pilha* p){
    int i;
    double aux_operand1, aux_operand2, aux_operand_tot;
    switch(op){
        case '+':
            while(p->top != 0){
                aux_operand1 = desempilhar_pilha(p);
                aux_operand2 = desempilhar_pilha(p);
                aux_operand_tot = aux_operand1 + aux_operand2;
                empilhar_pilha(aux_operand_tot, p);
            }
            break;
        case '-':
            while(p->top != 0){
                aux_operand1 = desempilhar_pilha(p);
                aux_operand2 = desempilhar_pilha(p);
                aux_operand_tot = aux_operand1 - aux_operand2;
                empilhar_pilha(aux_operand_tot, p);
            }
            break;
        case '*':
            while(p->top != 0){
                aux_operand1 = desempilhar_pilha(p);
                aux_operand2 = desempilhar_pilha(p);
                aux_operand_tot = aux_operand1 * aux_operand2;
                empilhar_pilha(aux_operand_tot, p);
            }
            break;

        case '/':
            while(p->top != 0){
                aux_operand1 = desempilhar_pilha(p);
                aux_operand2 = desempilhar_pilha(p);
                if((int)aux_operand2 == 0){
                    printf("DIVISAO POR 0!!!!\n");
                    empilhar_pilha(aux_operand2, p);
                    empilhar_pilha(aux_operand1, p);
                    break;
                }
                else{
                    aux_operand_tot = aux_operand1 / aux_operand2;
                    empilhar_pilha(aux_operand_tot, p);
                }
            }
            break;
    }
}
void normalcalc(char op, Pilha* p){
    double aux_operand1, aux_operand2, aux_operand_tot;
    aux_operand1 = desempilhar_pilha(p);
    aux_operand2 = desempilhar_pilha(p);
    switch(op){
        case '+':
            aux_operand_tot = aux_operand1 + aux_operand2;
            empilhar_pilha(aux_operand_tot, p);
            break;
        case '-':
            aux_operand_tot = aux_operand1 - aux_operand2;
            empilhar_pilha(aux_operand_tot, p);
            break;
        case '*':
            aux_operand_tot = aux_operand2 * aux_operand1;
            empilhar_pilha(aux_operand_tot, p);
            break;
        case '/':
            if((int)aux_operand2 == 0){
                printf("DIVISAO POR 0!!!!\n");
                empilhar_pilha(aux_operand2, p);
                empilhar_pilha(aux_operand1, p);
                break;
            }
            else{
                aux_operand_tot = aux_operand1 / aux_operand2;
                empilhar_pilha(aux_operand_tot, p);
                break;
            }
    }
}
void calc(){
    char expr[501];
    double aux_operand1, aux_operand2;
    int i;
    Pilha* calc_stack;
    calc_stack = cria_pilha(500);
    printcalcinstr();
    scanf(" %s", expr);
    while(strcmp(expr, "exit") != 0){
        if((expr[0] >= '0' && expr[0] <= '9')){
            empilhar_pilha(strtolfcalc(expr), calc_stack);
        }
        else if(is_operatorcalc(expr[0])){
            if(calc_stack->top < 1){
                printf("ERRO, PILHA NAO POSSUI OPERANDOS O SUFICIENTE PARA OPERACAO.\n");
            }
            else{
                if(expr[1] == '!'){
                    exclamationcalc(expr[0], calc_stack);
                }
                else{
                    normalcalc(expr[0], calc_stack);
                }
            }
        }
        else if(expr[0] == 'c'){
            if(calc_stack->top < 1){
                printf("ERRO, PILHA NAO POSSUI OPERANDOS O SUFICIENTE PARA OPERACAO.\n");
            }
            else{
                aux_operand1 = desempilhar_pilha(calc_stack);
                aux_operand2 = desempilhar_pilha(calc_stack);
                for(i = 0; i < aux_operand1; i++){
                    empilhar_pilha(aux_operand2, calc_stack);
                }
            }
        }
        printcalcinstr();
        mostra_pilha(calc_stack);
        printf(">> ");
        scanf(" %s", expr);
    }
    destroi_pilha(calc_stack);
}