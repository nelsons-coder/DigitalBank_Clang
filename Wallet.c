//
// Created by Nelson Sousa on 11/01/2022.
//
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto
#include "Wallet.h"
#include "Manager.h"

//Cria uma Carteira
Wallet createWallet(){
    Wallet w;
    printf("Introduza o nome da Carteira: ");
    fgets(w.name, 50 -1, stdin);
    w.name[strlen(w.name)-1]='\0';
    w.qtCryptos = 0;

    return w;
}



// Mostra a Carteira
void printWallet(Wallet w){
    printf("::::::::::::::::::::::::::::::\n");
    printf("::      ID: %d\n", w.id);
    printf("::      Descrição: %s\n", w.name);
    printf("::::::::::::::::::::::::::::::\n");
}

int listCryptosWallet(Wallet w){
    if(w.qtCryptos == 0){
        printf("Carteira vazia!\n");
        return -1;
    }
    for (int i = 0; i < w.qtCryptos; ++i) {
        printCrypto(w.crypto[i]);
    }
    return 1;
}


