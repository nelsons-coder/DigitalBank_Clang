//
// Created by Nelson Sousa on 11/01/2022.
//

#ifndef PROJETO_FINAL_C_NOVO_WALLET_H
#define PROJETO_FINAL_C_NOVO_WALLET_H
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto
#include "Crypto.h"


typedef struct sWallet {
    int id;
    char name[50];
    Crypto crypto[100];
    int qtCryptos;

}Wallet;
Wallet createWallet();
void printWallet(Wallet w);
int listCryptosWallet(Wallet w);

#endif //PROJETO_FINAL_C_NOVO_WALLET_H
