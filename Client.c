//
// Created by Nelson Sousa on 11/01/2022.
//
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto
#include "Client.h"
#include "CleanBuffer.h"
#include "Manager.h"

//Cria um cliente
Client createClient(){
    Client c;
    printf("Introduza o nome de Cliente: ");
    fgets(c.name, 100 -1, stdin);
    c.name[strlen(c.name)-1]='\0';

    printf("Introduza uma password: ");
    fgets(c.password, 100 -1, stdin);
    c.password[strlen(c.password)-1]='\0';

    printf("Introduza a morada do Cliente: ");
    fgets(c.adress, 100 -1, stdin);
    c.adress[strlen(c.adress)-1]='\0';

    printf("Introduza o numero de cartao de cidadao do Cliente: ");
    fgets(c.cc, 100 -1, stdin);
    c.cc[strlen(c.cc)-1]='\0';

    printf("Introduza o NIF do Cliente: ");
    scanf("%d",&c.nif);
    cleanBuffer();

    printf("Introduza o numero de Passaporte do Cliente: ");
    fgets(c.passport, 100 -1, stdin);
    c.passport[strlen(c.passport)-1]='\0';

    printf("Introduza o IBAN do Cliente: ");
    fgets(c.iban, 100 -1, stdin);
    c.iban[strlen(c.iban)-1]='\0';

    printf("Introduza o valor que deseja inciar: ");
    scanf("%f",&c.balance);
    cleanBuffer();

    c.wallet[0] = createWallet();
    c.qtWallet = 1;

    return c;
}

int findWalletIndex(Client c, int id){
    for (int i = 0; i < c.qtWallet; ++i) {
        if(id == c.wallet[i].id){
            return i;
        }
    }
}

void removeWallet(Client *c){
    int choice;
    printf("Qual o ID da carteira que pretende remover? ");
    scanf("%d", &choice);
    cleanBuffer();
    if(c->wallet[findWalletIndex(*c, choice)].qtCryptos != 0){
        printf("ERRO: Carteira contêm moedas!\n");
        return;
    }
    for (int i = findWalletIndex(*c, choice); i < c->qtWallet; ++i) {
        c->wallet[i] = c->wallet[i + 1];
    }
    c->qtWallet--;
    printf("Sucesso: Carteira eliminada!!\n");
}


//Lista as Carteiras de um cliente
void listWallets(Client c){
    for (int i = 0; i < c.qtWallet; ++i) {
        printWallet(c.wallet[i]);
    }
}


//Mostra um Cliente "Info Completa"
void printClient(Client c){
    printf("::::::::::::::::::::::::::::::\n");
    printf("::      Nome: %s\n", c.name);
    printf("::      Numero: %d\n", c.numClient);
    printf("::      Morada: %s\n", c.adress);
    printf("::      NIF: %d\n",c.nif);
    printf("::      Cartao de Cidadao: %s\n",c.cc);
    printf("::      Passaporte: %s\n",c.passport);
    printf("::      IBAN: %s\n",c.iban);
    printf("::::::::::::::::::::::::::::::\n");
}

//Mostra um CLiente "Info Básica"
void printClientInfo(Client c){
    printf("::::::::::::::::::::::::::::::\n");
    printf("::      Nome: %s\n", c.name);
    printf("::      Numero: %d\n", c.numClient);
    printf("::::::::::::::::::::::::::::::\n");
}
 void checkWallet(Client c){
     int num;
     listWallets(c);
     printf("Digite qual o numero da carteira que deseja aceder: \n");
     scanf("%d", &num);
     cleanBuffer();
    for (int i = 0; i < c.qtWallet ; ++i) {
       if(num == c.wallet[i].id) {
           listCryptosWallet(c.wallet[i]);
       }
    }
}

void checkBalance(Client c){
    printf("Saldo: %.2f\n", c.balance);
}











