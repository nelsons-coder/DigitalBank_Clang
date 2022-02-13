//
// Created by Nelson Sousa on 11/01/2022.
//

#ifndef PROJETO_FINAL_C_NOVO_CRYPTO_H
#define PROJETO_FINAL_C_NOVO_CRYPTO_H
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto

//Estrutura Crypto
typedef struct sCrypto{
    char nameDescription[4];
    float value;
} Crypto;
//Funções
void printCrypto(Crypto y);
Crypto createCrypto();
#endif //PROJETO_FINAL_C_NOVO_CRYPTO_H
