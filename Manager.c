//
// Created by Nelson Sousa on 11/01/2022.
//
//Librarias de C
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Includes do projeto
#include "Manager.h"
#include "CleanBuffer.h"
#include "Client.h"

//Inicializa o Manager
void initManager(Manager *m){
    m->qtClients = 0;
    m->qtCrypto = 0;
    m->counterClients = 1;
    m->counterWallets = 1;
}

//Adiciona um cliente
int addClient(Manager *m, Client c){
    if(m->qtClients == 100){
        return 1;
    }
    c.numClient = m->counterClients;
    c.wallet->id = m->counterWallets;

    m->client[m->qtClients] = c;
    m->qtClients++;
    m->counterClients++;
    m->counterWallets++;

    return 0;
}

int addWallet(Manager *m, Client *c){
    if(c->qtWallet == 10){
        printf("Numero de carteiras alcançado!\n");
        return 1;
    }
    c->wallet[c->qtWallet] = createWallet();
    c->qtWallet++;
    c->wallet[c->qtWallet - 1].id = m->counterWallets;
    m->counterWallets++;
    printf("Sucesso: Carteira criada!!\n");
    return -1;
}

void listAllWallets(Manager m){

    for (int i = 0; i < m.qtClients ; ++i) {
        printf("* - CLiente: %s\n", m.client[i].name);
        listWallets(m.client[i]);
    }
}

//Lista todos os clientes
void listClients(Manager m){
    if(m.qtClients == 0){
        printf("ERRO: Não existe nenhum cliente!\n");
    } else {
        for(int i=0; i < m.qtClients; i++){
            printClientInfo(m.client[i]);
        }
    }
}

// Encontrar cliente
void findClient( Manager m){
    int num;
    printf("Indique o número do cliente que pretende aceder: ");
    scanf("%d", &num);
    cleanBuffer();
    for (int i = 0; i < m.qtClients ; ++i) {
        if(m.client[i].numClient == num){
            printClient(m.client[i]);
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}
// Lista todas as Moedas
int listCryptos(Manager m){
    if(m.qtCrypto == 0) return -1;
    for (int i = 0; i < m.qtCrypto; ++i) {
        printCrypto(m.crypto[i]);
    }
}

//Remove um Cliente
void removeClient(Manager *m){
    int num;
    printf("Indique o número do cliente que pretende aceder: ");
    scanf("%d", &num);
    cleanBuffer();
    for (int i = 0; i < m->qtClients ; ++i) {
        if(m->client[i].numClient == num){
            for (int j = num - 1; j < m->qtClients - 1; j++) {
                m->client[i] = m->client[i + 1];
            }
            m->qtClients--;
            printf("Cliente eliminado!\n");
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

//Edita um CLiente
void editClient(Manager *m){
    int num;
    int choice;
    printf("Indique o número do cliente que pretende editar: ");
    scanf("%d", &num);
    cleanBuffer();
    for (int i = 0; i < m->qtClients ; ++i) {
        if(m->client[i].numClient == num) {
            printf("1 - Morada\n");
            printf("2 - IBAN\n");
            printf("3 - Saldo\n");
            printf("O que pretende editar? ");
            scanf("%d", &choice);
            cleanBuffer();
            switch (choice) {
                case 1:
                    printf("A morada atual do cliente é %s!\n", m->client[i].adress);
                    printf("Digite a nova morada: ");
                    fgets(m->client[i].adress, 100 - 1, stdin);
                    printf("Morada editada!\n");
                    m->client[i].adress[strlen(m->client[i].adress) - 1] = '\0';
                    return;
                case 2:
                    printf("O IBAN atual do cliente é %s!\n", m->client[i].iban);
                    printf("Digite o novo IBAN: ");
                    fgets(m->client[i].iban, 100 - 1, stdin);
                    m->client[i].iban[strlen(m->client[i].iban) - 1] = '\0';
                    printf("IBAN editado!\n");
                    return;
                case 3:
                    printf("O saldo atual do cliente é de %.2f€!\n", m->client[i].balance);
                    printf("Digite o novo saldo: ");
                    scanf("%f", &m->client[i].balance);
                    cleanBuffer();
                    printf("Saldo editado!\n");
                    return;
                default:
                    return;
            }
        }
    }
    printf("ERRO: Cliente nao encontrado!\n");
}

int addCryptoManager(Manager *m, Crypto y){
    if(m->qtCrypto == 100){
        printf("ERRO: Quantidade máxima de moedas/stocks alcançada!\n");
    }
    for (int i = 0; i < m->qtCrypto; ++i) {
        if(strcmp(y.nameDescription, m->crypto[i].nameDescription) == 0 ){
            printf("ERRO: Moeda existente!\n");
            return -1;
        }
    }
    if(y.value < 0){
        printf("ERRO: Valor inválido!\n");
        return -2;
    }
    m->crypto[m->qtCrypto] = y;
    m->qtCrypto++;
    return 0;
}

//Remove uma Moeda
void removeCrypto(Manager *m) {
    char cryp[4];
    printf("Indique qual a moeda que pretende eliminar: ");
    fgets(cryp, 4, stdin);
    cryp[strlen(cryp)] = '\0';
    for (int i = 0; i < m->qtCrypto; ++i) {
        if (strcmp(m->crypto[i].nameDescription, cryp) == 0) {
            for (int k = i; k < m->qtCrypto - 1; k++) {
                m->crypto[i] = m->crypto[i + 1];
            }
            m->qtCrypto--;
            printf("Sucesso: Moeda eliminada!\n");
            return;
        }
    }
    printf("ERRO: Moeda não encontrada!\n");
}

//Edita uma moeda
void editCrypto(Manager *m){
    char cryp[4];
    int crypIndex;
    printf("Indique qual a moeda que pretende editar: ");
    fgets(cryp, 4 , stdin);
    cryp[strlen(cryp)] = '\0';
    for (int i = 0; i < m->qtCrypto; ++i) {
        if(strcmp(m->crypto[i].nameDescription, cryp) == 0) {
            float num;
            printf("Digite o novo valor para a moeda: ");
            scanf("%f", &num);
            cleanBuffer();
            if(num < 0){
                printf("ERRO: Valor inválido!\n");
                return;
            }
            m->crypto[i].value = num;
            printf("Moeda \"%s\" tem o novo valor de %f€\n", m->crypto[i].nameDescription, m->crypto[i].value);
            return;
        }
    }
    printf("ERRO: Moeda não encontrada!\n");
}

// guardar
void save(Manager *m){
    FILE * file = fopen("manager.bin", "wb+");

    if(file  ==NULL || m == NULL){
        return;
    }
    fwrite(m, sizeof (Manager), 1, file);
    fclose(file);
}

//
void read(Manager * m){
    FILE *file = fopen("manager.bin", "rb+");

    if(file == NULL){
        return;
    }

    fread(m, sizeof(Manager), 1, file);
    fclose(file);
}

//Comprar moedas

void buyCryptoAndStocks(Manager m, Client *c) {
    //global variables
    char crySto[100];
    float value;
    int wallet;
    printf("De momento, o seu saldo é de %.2f€\n", c->balance);
    printf("-----------------------\n");
    printf("Escreva a moeda que quer comprar!\n");
    fgets(crySto, 100 - 1, stdin);
    crySto[strlen(crySto) - 1] = '\0';
    for (int i = 0; i < m.qtCrypto; i++) {
        if (strcmp(m.crypto[i].nameDescription, crySto) == 0) {
            printf("Qual o valor que deseja comprar?\n");
            scanf("%f", &value);
            cleanBuffer();
            if(value > c->balance){
                printf("ERRO: Não tem saldo suficiente para essa compra!!!\n");
                return;
            }
            else{
                c->balance -= value;
                for (int j = 0; j < c->qtWallet; ++j) {
                    printWallet(c->wallet[j]);
                }
                printf("Qual o id da carteira em que deseja adicionar a compra?\n");
                scanf("%d", &wallet);
                cleanBuffer();
                for (int j = 0; j < c->qtWallet; ++j) {
                    if(c->wallet[j].id == wallet){
                        for (int k = 0; k < c->wallet[j].qtCryptos ; k++) {
                            if (strcmp(c->wallet[j].crypto[k].nameDescription, crySto) == 0) {
                                c->wallet[j].crypto[k].value += value / m.crypto[i].value;
                                printf("Comprou %f de %s!!\n", value / m.crypto[i].value, crySto);
                                return;
                            }
                        }
                        c->wallet[j].crypto[c->wallet[j].qtCryptos] = m.crypto[i];
                        c->wallet[j].crypto[c->wallet[j].qtCryptos].value = value / m.crypto[i].value;
                        printf("Comprou %f de %s!!\n", c->wallet[j].crypto[c->wallet[j].qtCryptos].value, crySto);
                        c->wallet[j].qtCryptos++;
                        return;
                    }
                }
            }
        }
    }
    printf("ERRO: Moeda nao encontrada!!!\n");
}


void sellCrypto(Manager admin, Client *c){
    char crySto[100];
    int wallet;
    for (int j = 0; j < c->qtWallet; ++j) {
        printWallet(c->wallet[j]);
    }
        printf("Qual o id da carteira em que deseja fazer a venda?\n");
        scanf("%d", &wallet);
        cleanBuffer();
        for (int j = 0; j < c->qtWallet; j++) {
            if (c->wallet[j].id == wallet) {
                for (int i = 0; i < c->wallet[j].qtCryptos; i++) {
                    printCrypto(c->wallet[j].crypto[i]);
                }
                printf("Escreva a moeda que quer vender!\n");
                fgets(crySto, 100 - 1, stdin);
                crySto[strlen(crySto) - 1] = '\0';
                for (int k = 0; k < c->wallet[j].qtCryptos; k++) {
                    if (strcmp(c->wallet[j].crypto[k].nameDescription, crySto) == 0) {
                        float valueToSell;
                        float finalValue = 0;
                        for (int y = 0; y < admin.qtCrypto; ++y) {
                            if (strcmp(crySto, admin.crypto[y].nameDescription) == 0) {
                                printf("Tens %f de %s!\n", c->wallet[j].crypto[k].value, admin.crypto[y].nameDescription);
                                printf("A %s de momento vale %.2f€\n", admin.crypto[y].nameDescription, admin.crypto[y].value);
                                printf("Neste momento tens %.2f€ desta moeda!\n", admin.crypto[y].value * c->wallet[j].crypto[k].value);
                                printf("Que quantidade deseja vender?\n");
                                scanf("%f", &valueToSell);
                                cleanBuffer();
                                valueToSell = valueToSell / admin.crypto[y].value;
                                c->wallet[j].crypto[k].value -= valueToSell;
                                if (c->wallet[j].crypto[k].value <= 0.000002) {
                                    for (int h = j; h < c->wallet[j].qtCryptos - 1; h++) {
                                        c->wallet[j].crypto[k] = c->wallet[j].crypto[k + 1];
                                    }
                                    c->wallet[j].qtCryptos--;
                                }
                                finalValue = valueToSell * admin.crypto[y].value;
                                c->balance += finalValue;
                                printf("Sucesso: Moeda vendida!!\n");
                                return;
                            }
                        }
                    }
                }
            }
            printf("ERRO: Carteira nao encontrada!!!\n");
            return;
        }
}


void consultClientWallet(Manager m) {
    int num;
    int num2;
    printf("Digite o numero de qual cliente deseja aceder à carteira: \n");
    scanf("%d", &num);
    cleanBuffer();
    for (int i = 0; i < m.qtClients; ++i) {
        if (num == m.client[i].numClient) {
            listWallets(m.client[i]);
            printf("Digite o numero da carteira que pretende aceder: \n");
            scanf("%d", &num2);
            cleanBuffer();
            for (int j = 0; j <  m.client[i].qtWallet; ++j) {
                if(m.client[i].wallet[j].id == num2){
                    if(m.client[i].wallet[j].qtCryptos == 0){
                        printf("Carteira vazia!\n");
                        return;
                    }
                    for (int k = 0; k < m.client[i].wallet[j].qtCryptos; ++k) {
                        printCrypto(m.client[i].wallet[j].crypto[k]);
                    }

                }
            }
            printf("Carteira não encontrada!\n");
            return;
        }
    }
    printf("Cliente não encontrado!\n");
}
