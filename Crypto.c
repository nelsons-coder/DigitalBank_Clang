//
// Created by Nelson Sousa on 11/01/2022.
//
//Librarias de C
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Includes do projeto
#include "Crypto.h"
#include "CleanBuffer.h"

// Cria uma Moeda
Crypto createCrypto(){
    Crypto y;
    printf("Introduza o nome da Stock/Moeda: Ex:(\"BTC\") Máximo 3 letras.");
    fgets(y.nameDescription, 4, stdin);
    y.nameDescription[strlen(y.nameDescription)]='\0';
    for(int i = 0; i <strlen(y.nameDescription); i++){
        y.nameDescription[i] = toupper(y.nameDescription[i]);
    }
    cleanBuffer();
    printf("Introduza o valor do Stock/Moeda: Ex:(\"5.6\") ");
    scanf("%f", &y.value);
    cleanBuffer();
    return y;
}

//Mostra a Moeda
void printCrypto(Crypto y){
    printf(":::::::::::::::::::::::::::\n");
    printf("::      Nome: %s\n", y.nameDescription);
    printf("::      Valor: %f\n", y.value);
    printf(":::::::::::::::::::::::::::\n");
}