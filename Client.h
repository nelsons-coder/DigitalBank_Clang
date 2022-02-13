//
// Created by Nelson Sousa on 11/01/2022.
//

#ifndef PROJETO_FINAL_C_NOVO_CLIENT_H
#define PROJETO_FINAL_C_NOVO_CLIENT_H
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto
#include "Wallet.h"
typedef struct sClient{
    char name[100];
    char password[100];
    char adress[100];
    int nif;
    char cc[100];
    char passport[100];
    int numClient;
    char iban[100];
    int qtWallet;
    float balance;
    Wallet wallet[10];
} Client;
//Funções
void printClient(Client c);
void printClientInfo(Client c);
Client createClient();
void listWallets(Client c);
void checkWallet(Client c);
void removeWallet(Client *c);
int findWalletIndex(Client c, int id);
void checkBalance(Client c);

#endif //PROJETO_FINAL_C_NOVO_CLIENT_H
