#include <stdio.h>
#include <stdlib.h>
#include "Manager.h"
#include "CleanBuffer.h"
#include "Menus.h"

int main() {
    Manager admin;
    initManager(&admin);
    read(&admin);
    admin.id = 0;
    char pass[15] = "admin";
    int aux = 2;
    int numClient;
    char password[15];
    do {
        printf("Introduza o seu nº de Cliente: ");
        scanf("%d", &numClient);
        cleanBuffer();
        printf("Introduza a sua password: ");
        fgets(password, 15 - 1, stdin);
        password[strlen(password) - 1] = '\0';
        if (numClient == 0 && strcmp(password, "admin") == 0) {
            int res = menuManager(&admin);
            if (res == -1) aux = 1;
        }
        for (int i = 0; i < admin.qtClients; i++){
            if (admin.client[i].numClient == numClient && strcmp(admin.client[i].password, password) == 0) {
                int res = menuClient(&admin.client[i], &admin);
                if (res == -1) aux = 1;
            }

        }

    }while(aux != 1);
    save(&admin);
    return 0;
}

