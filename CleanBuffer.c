//
// Created by Nelson Sousa on 11/01/2022.
//
//Librarias de C
#include <stdio.h>
#include <string.h>
//Includes do projeto
#include "CleanBuffer.h"

// Limpa o Buffer
void cleanBuffer(){
    while (getchar() != '\n' && getchar() != EOF);
}