#ifndef SPISOK
#define SPISOK

#include <stdio.h>
#include <stdlib.h>

#define SIZE_DATA 30

struct str_spisok{
    int* data;
    int* next;
    int* prev;
    int head;
    int tail;
    int free;
    int size;
};

void Vstavka(str_spisok* spisok, int index, int value);

void Delete(str_spisok* spisok, int index);

#endif