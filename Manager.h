//
// Created by Nelson Sousa on 11/01/2022.
//

#ifndef PROJETO_FINAL_C_NOVO_MANAGER_H
#define PROJETO_FINAL_C_NOVO_MANAGER_H
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto
#include "Client.h"

typedef struct sManager{
    int id;
    char password[15];
    Client client[100];
    int qtClients;
    Crypto crypto[100];
    int qtCrypto;
    int counterWallets;
    int counterClients;
} Manager;
void initManager(Manager *m);
int addClient(Manager *m, Client c);
void editClient(Manager *m);
void removeCrypto(Manager *m);
void editCrypto(Manager *m);
int listCryptos(Manager m);
void listClients(Manager m);
void findClient(Manager m);
void removeClient(Manager *m);
void buyCryptoAndStocks(Manager admin, Client *c);
void sellCrypto(Manager admin, Client *c);
void save(Manager *m);
void read(Manager *m);
int addCryptoManager(Manager *m, Crypto y);
int addWallet(Manager *m, Client *c);
void consultClientWallet(Manager m);
void listAllWallets(Manager m);

#endif //PROJETO_FINAL_C_NOVO_MANAGER_H
