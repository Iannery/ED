#include <stdio.h>
#include <math.h>
#include <string.h>

int converter(char op){
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
double strtoint(char* expr){
    int i, m = 0, j, auxconv, tamstr;
    double tot = 0;
    tamstr = strlen(expr);
    for(i = 0; i < tamstr; i++){
        if(expr[i] == '.'){
            m = i;
        }
    }
    if(m){
        for(i = (m - 1), j = 0; j < m; i--, j++){
            auxconv = converter(expr[j]);
            tot += auxconv * pow(10, i);
        }
        for(i = 0, j = m + 1; j < tamstr; i++, j++){
            auxconv = converter(expr[j]);
            tot += auxconv / pow(10, i + 1);
        }
    }
    else{
        for(i = (tamstr - 1), j = 0; j < tamstr; i--, j++){
            auxconv = converter(expr[j]);
            tot += auxconv * pow(10, i);
        }
    }
    return tot;


}

int main(){
    char alo[50];
    double t;
    scanf("%s", alo);
    t = strtoint(alo);
    printf("string = %s\nnum = %lf\n", alo, t);
    return 0;
}