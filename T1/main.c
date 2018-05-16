#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
int priority(char op){
    if(op == '*' || op == '/'){
        return 2;
    }
    if(op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int is_operand(char op){
    if( op == '1' || op == '2' || op == '3' || op == '4' ||
        op == '5' || op == '6' || op == '7' || op == '8' ||
        op == '9' || op == ' ' || op == '.' || op == ',' ||
        op == '0' || (op >= 'A' && op <= 'Z')){

        return 1;
    }
    else{
        return 0;
    }
    
}

int is_operator(char op){
    if(op == '*' || op == '/' || op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

void inf_to_postf(char* exp_infix, char* exp_postfix){
    Pilha* itp_stack;
    int i, j;
    itp_stack = cria_pilha(strlen(exp_infix));
    for(i = 0, j = 0; i < strlen(exp_infix); i++){
        puts("TUDO BEM ATE AQUI");
        if(is_operand(exp_infix[i])){
            exp_postfix[j] = exp_infix[i];
            j++;
        }
        else if(is_operator(exp_infix[i])){
            while((!pilha_vazia(itp_stack)) && (priority(topo_pilha(itp_stack)) >= priority(exp_infix[i]))){
                exp_postfix[j] = desempilhar_pilha(itp_stack);
                j++;
            }
            empilhar_pilha(exp_infix[i], itp_stack);
        }
        else if(exp_infix[i] == '('){
            empilhar_pilha(exp_infix[i], itp_stack);
        }
        else if(exp_infix[i] = ')'){
            while(topo_pilha(itp_stack) != '('){
                exp_postfix[j] = desempilhar_pilha(itp_stack);
                j++;
            }
        }
        else{
            puts("Expressao invalida");
        }
    }
    while(!pilha_vazia(itp_stack)){
        exp_postfix[j] = desempilhar_pilha(itp_stack);
        j++;
    }
    exp_postfix[j] = '\0';
    destroi_pilha(itp_stack);
}

int validate_exp(char* expression){
    Pilha* val_stack;
    int exp_size, i, validvar = 1;
    exp_size = strlen(expression);
    val_stack = cria_pilha(exp_size);
    for(i = 0; i < exp_size; i++){
        switch(expression[i]){
            case '(':
                empilhar_pilha('(', val_stack);
                break;
            case ')':
                if(pilha_vazia(val_stack)){
                    puts("Equacao invalida");
                    validvar = 0;
                }
                else if(desempilhar_pilha(val_stack) == '('){
                }
                break;
        }
    }
    if(!pilha_vazia(val_stack)){
        puts("Equacao invalida");
        validvar = 0;
    }
    destroi_pilha(val_stack);
    return validvar;
}

int resprob(){
    char expression[101], exp_postfix[101];
    puts("Digita uma string");
    getchar();
    gets(expression);
    printf("a string tem %d de tamanho\n", strlen(expression));
    if(!validate_exp(expression)){
        return 0;
    }
    
    inf_to_postf(expression, exp_postfix);
    puts("Expressoes:::::");
    puts(expression);
    puts(exp_postfix);


}

// ---------------------------MISC------------------------------------------

void printmenu(){
    printf("Escolha uma opcao:\n");
    printf("1.\tResolucao de expressao\n2.\tCalculadora\n3.\tSair\n\n>>");
}
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
                // calc();
                break;
            case 3:
                flagrun = 0;
                break;
        }
    }
    return 0;
}