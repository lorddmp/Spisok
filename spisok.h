#ifndef SPISOK
#define SPISOK

#include <stdio.h>
#include <stdlib.h>

struct str_spisok{
    int* data;
    int* next;
    int* prev;
    int head;
    int tail;
    int free;
};

void Vstavka(str_spisok* spisok, int index, int value);

void Delete(str_spisok* spisok, int index);

#endif