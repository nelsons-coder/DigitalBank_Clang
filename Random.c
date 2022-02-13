//
// Created by 35193 on 31/01/2022.
//

#include "Random.h"
#include <time.h>
#include <stdlib.h>

int Random(){
    srand ( time(NULL) );
    int r = rand() % 2;
    return r;
}

float Random2(){
    srand ( time(NULL) );
    float r2 = (rand() % 10);
    return r2/100;
}

void setValue(Manager *m) {
    if (Random() == 0) {
        for (int i = 0; i < m->qtCrypto; ++i) {
            m->crypto[i].value += (m->crypto[i].value * Random2());
        }
    } else {
        for (int i = 0; i < m->qtCrypto; ++i) {
            m->crypto->value -= m->crypto->value * Random2();
        }
    }
}