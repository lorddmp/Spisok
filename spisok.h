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

int Init_Spisok(str_spisok* spisok);

int Data_Vstavka(str_spisok* spisok, int index, int value);

int Data_Delete(str_spisok* spisok, int index);

int List_Vstavka(str_spisok* spisok, int index, int value);

int List_Delete(str_spisok* spisok, int index);

void Write_Spisok(str_spisok spisok);

void Print_Spisok(str_spisok spisok);

void List_Destructor(str_spisok spisok);

#endif