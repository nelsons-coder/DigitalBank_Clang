//
// Created by 35193 on 11/01/2022.
//

#include "Menus.h"
#include "CleanBuffer.h"
#include "Client.h"
#include "Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Random.h"


void menuManageClients(Manager *m){
    int opcao;
    do {
        printf(":::::::::::::  Gestão Clientes  :::::::::::::\n");
        printf("::                                         ::\n");
        printf("::      1. Criar cliente                   ::\n");
        printf("::      2. Eliminar cliente                ::\n");
        printf("::      3. Listar cliente                  ::\n");
        printf("::      4. Consultar cliente               ::\n");
        printf("::      5. Listar todas as carteiras       ::\n");
        printf("::      6. Consultar Carteira de cliente   ::\n");
        printf("::      7. Editar cliente                  ::\n");
        printf("::      9. Voltar                          ::\n");
        printf("::                                         ::\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::\n");
        scanf("%d", &opcao);
        cleanBuffer();
        switch (opcao) {
            case 1:
                addClient(m, createClient());
                break;
            case 2:
                listClients(*m);
                removeClient(m);
                break;
            case 3:
                listClients(*m);
                break;
            case 4:
                listClients(*m);
                findClient(*m);
                break;
            case 5:
                listAllWallets(*m);
                break;
            case 6:
                listClients(*m);
                consultClientWallet(*m);
                break;
            case 7:
                listClients(*m);
                editClient(m);
                break;
            case 9:
                return;
            default:
                break;
        }
    }while(opcao != 9);
}

void menuManageCrypto(Manager *m){
    int opcao;
    do {
        printf(":::::::::  Gestão Moedas/Stocks  :::::::::\n");
        printf("::                                      ::\n");
        printf("::      1. Criar moeda/stock            ::\n");
        printf("::      2. Eliminar moeda/stock         ::\n");
        printf("::      3. Listar moeda/stock           ::\n");
        printf("::      4. Editar moeda/stock           ::\n");
        printf("::      9. Voltar                       ::\n");
        printf("::                                      ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::\n");
        scanf("%d", &opcao);
        cleanBuffer();
        switch (opcao) {
            case 1:
                addCryptoManager(m, createCrypto());
                break;
            case 2:
                listCryptos(*m);
                removeCrypto(m);
                break;
            case 3:
                if(listCryptos(*m) == -1) printf("ERRO: Base de dados vazia!\n");
                break;
            case 4:
                listCryptos(*m);
                editCrypto(m);
                break;
            case 9:
                return;
            default:
                break;
        }
    }while(opcao != 9);
}

int menuManager(Manager *m){
    int opcao;
    do {
        printf(":::::::  Menu Manager  ::::::::\n");
        printf("::                           ::\n");
        printf("::     1. Gerir Clientes     ::\n");
        printf("::     2. Gerir moedas       ::\n");
        printf("::     9. Logout             ::\n");
        printf("::     0. Sair               ::\n");
        printf("::                           ::\n");
        printf(":::::::::::::::::::::::::::::::\n");
        scanf("%d", &opcao);
        cleanBuffer();
        switch (opcao) {
            case 1:
                menuManageClients(m);
                break;
            case 2:
                menuManageCrypto(m);
                break;
            case 9:
                setValue(m);
                return 0;
            case 0:
                return -1;
            default:
                break;
        }
    }while(opcao != 0);
}

int menuManageWallets(Manager *m,Client *c){
    int opcao;
    do {
        printf("::::::::  Gestão Carteiras  ::::::::\n");
        printf("::                                ::\n");
        printf("::     1. Criar carteira          ::\n");
        printf("::     2. Eliminar carteira       ::\n");
        printf("::     3. Listar carteiras        ::\n");
        printf("::     4. Consular carteira       ::\n");
        printf("::     5. Consultar Saldo         ::\n");
        printf("::     9. Voltar                  ::\n");
        printf("::                                ::\n");
        printf("::::::::::::::::::::::::::::::::::::\n");
        scanf("%d", &opcao);
        cleanBuffer();
        switch (opcao) {
            case 1:
                addWallet(m,c);
                break;
            case 2:
                listWallets(*c);
                removeWallet(c);
                break;
            case 3:
                listWallets(*c);
                break;
            case 4:
                checkWallet( *c);
                break;
            case 5:
                checkBalance(*c);
                break;
            case 9:
                save(m);
                return 0;
            case 0:
                return -1;
            default:
                break;
        }
    }while(opcao != 9);
}

int menuManageBuySell(Manager *m, Client *c){
    int opcao;
    do {
        printf("::::::  Gestão Moedas  ::::::\n");
        printf("::                         ::\n");
        printf("::    1. Comprar moeda     ::\n");
        printf("::    2. Vender moeda      ::\n");
        printf("::    3. Listar moedas     ::\n");
        printf("::    9. Voltar            ::\n");
        printf("::                         ::\n");
        printf(":::::::::::::::::::::::::::::\n");
        scanf("%d", &opcao);
        cleanBuffer();
        switch (opcao) {
            case 1:
                listCryptos(*m);
                buyCryptoAndStocks(*m, c);
                break;
            case 2:
                sellCrypto(*m,c);
                break;
            case 3:
                listCryptos(*m);
                break;
            case 9:
                return 0;
            case 0:
                return -1;
            default:
                break;
        }
    }while(opcao != 9);
}

int menuClient(Client *c, Manager *m){
    int opcao;
    do {
        printf("::::::::::  Menu Cliente  ::::::::::\n");
        printf("::                                ::\n");
        printf("::      1. Gerir Carteiras        ::\n");
        printf("::      2. Compras/Vendas         ::\n");
        printf("::      9. Logout                 ::\n");
        printf("::      0. Sair                   ::\n");
        printf("::                                ::\n");
        printf("::::::::::::::::::::::::::::::::::::\n");
        scanf("%d", &opcao);
        cleanBuffer();
        switch (opcao) {
            case 1:
                menuManageWallets(m, c);
                break;
            case 2:
                menuManageBuySell(m, c);
                break;
            case 9:
                setValue(m);
                return 0;
            case 0:
                return -1;
            default:
                break;
        }
    }while(opcao != 0);
}


