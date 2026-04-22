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

str_spisok Init_Spisok(void);

void LVstavka(str_spisok* spisok, int index, int value);

void LDelete(str_spisok* spisok, int index);

void Print_Spisok(str_spisok spisok);

#endif