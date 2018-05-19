#####################################################
# UNIVERSIDADE DE BRASILIA                          #
# MATERIA: ED - 116319                              #
# Ian Nery Bandeira - 17/0144739                    #
# gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0                #
# SO - Ubuntu 18.04                                 #
# Compilado no terminal / Editado em VS Code        #
#####################################################

Bibliotecas utilizadas::

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhachar.h"
#include "pilhadouble.h"
#include "resprob.h"
#include "calculator.h"

INSTRUÇÕES DE COMPILAÇÃO::

DEVE SER COMPILADO EM UBUNTU
gcc -c pilhachar.c
gcc -c pilhadouble.c
gcc -c calculator.c pilhachar.c pilhadouble.c -lm
gcc -c resprob.c pilhachar.c pilhadouble.c -lm
gcc -o main main.c calculator.o resprob.o pilhachar.o pilhadouble.o -lm


execute o arquivo ./main