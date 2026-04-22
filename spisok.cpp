#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "spisok.h"

int Find_Index_In_Next(str_spisok* spisok, int counter, int index_next);

#define IF_ERROR_CALLOC(arg)                \
do                                          \
{                                           \
    if (arg == NULL)                        \
    {                                       \
        printf("CALLOC ERROR\n");           \
        return 1;                           \
    }                                       \
} while (0)

int Init_Spisok(str_spisok* spisok)
{
    spisok->data = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok->next = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok->prev = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok->free = 1;
    spisok->head = 0;                                           //индекс первого элемента списка в data
    spisok->tail = 0;                                           //индекс последнего элемента списка в data
    spisok->size = 0;                                           //количество элементов в списке (можно использовать как индикатор для tail или
                                                                //чтобы после индекса больше чем элементов в data элемент ставился в конец)
    IF_ERROR_CALLOC(spisok->data);
    IF_ERROR_CALLOC(spisok->next);
    IF_ERROR_CALLOC(spisok->prev);

    for (int i = 1; i < SIZE_DATA - 1; i++)
        spisok->next[i] = i + 1;

    for (int i = 2; i < SIZE_DATA - 1; i++)
        spisok->prev[i] = -1;
    
    return 0;
}

//-----------------------------------------------------------------------------

int Data_Vstavka(str_spisok* spisok, int index, int value)
{
    if (spisok->prev[index] == -1)
    {
        fprintf(stderr, "Illegal index in insert\n");
        return 1;
    }

    if (index == 0)
        spisok->head = spisok->free;
    else if (index == spisok->tail)
        spisok->tail = spisok->free;

    int next_free = spisok->next[spisok->free];
    spisok->data[spisok->free] = value;

    spisok->prev[spisok->free] = spisok->prev[spisok->next[index]];
    spisok->prev[spisok->next[index]] = spisok->free;

    spisok->next[spisok->free] = spisok->next[index];
    spisok->next[index] = spisok->free;

    spisok->free = next_free;

    spisok->size++;

    return 0;
}

int Data_Delete(str_spisok* spisok, int del_index)
{
    if (spisok->prev[del_index] == -1)
    {
        fprintf(stderr, "Illegal index in insert\n");
        return 1;
    }

    if (del_index == spisok->head)
        spisok->head = spisok->next[del_index];
    else if (del_index == spisok->tail)
        spisok->tail = spisok->prev[del_index];

    spisok->data[del_index] = 0;

    spisok->next[spisok->prev[del_index]] = spisok->next[del_index];
    spisok->prev[spisok->next[del_index]] = spisok->prev[del_index];
    spisok->prev[del_index] = -1;
    spisok->next[del_index] = spisok->free;

    spisok->free = del_index;
    spisok->size--;

    return 0;
}

//-----------------------------------------------------------------------------

int Find_Index_In_Next(str_spisok* spisok, int counter, int index_next)
{
    if (spisok->head == 0)
        counter = 0;

    if (counter > 0)
    {
        index_next = spisok->next[index_next];            
        counter--;
        Find_Index_In_Next(spisok, counter, index_next);
    }
    
    return index_next;
}

int List_Vstavka(str_spisok* spisok, int index, int value)
{
    int index_next = Find_Index_In_Next(spisok, index, 0);       //возвращает индекс в next, куда надо записать индекс нового элемента и откуда взять индекс следующего после него
    
    Data_Vstavka(spisok, index_next, value);

    return 0;
}

int List_Delete(str_spisok* spisok, int index)
{
    int del_index = Find_Index_In_Next(spisok, index, 0);

    Data_Delete (spisok, del_index);

    return 0;
}

//-----------------------------------------------------------------

void Write_Spisok(str_spisok spisok)
{
    printf("data: ");
    for (int i = 0; i < SIZE_DATA; i++)
        printf("%4d", spisok.data[i]);
    printf("\n");

    printf("next: ");
    for (int i = 0; i < SIZE_DATA; i++)
        printf("%4d", spisok.next[i]);
    printf("\n");

    printf("prev: ");
    for (int i = 0; i < SIZE_DATA; i++)
        printf("%4d", spisok.prev[i]);
    printf("\n");

    printf("free = %d\n", spisok.free);
    printf("head = %d\n", spisok.head);
    printf("tail = %d\n", spisok.tail);
    printf("size = %d\n", spisok.size);

    printf("(0) ");

    for (int i = spisok.head; i != 0; i = spisok.next[i])
        printf("%d ", spisok.data[i]);

    printf("\n\n----------------------------------\n\n");
}

//----------------------------------------------------------------

void Print_Spisok(str_spisok spisok)
{
    FILE* fp = fopen("Spisok.txt", "w");
    if (fp == NULL)
        fprintf(stderr, "ERROR IN OPENING DUMP FILE\n");

    fprintf(fp, "Digraph G{\n");
    fprintf(fp, "rankdir = LR;\n");
    fprintf(fp, "splines = curved;\n");

    for (int index = 0; index <= spisok.size; index++)
        fprintf(fp, "node%d [shape = record, color = black, label=\"%d | <f2> %d| {<f0> %d| <f1> %d}\"];\n", index, spisok.data[index], index, spisok.next[index], spisok.prev[index]);

    for (int index = 0; index < spisok.size; index++)
        fprintf(fp, "node%d:<f2>->node%d:<f2>[color = blue];\n", index, index+1);

    for (int index = spisok.head; index != 0; index = spisok.next[index])
        fprintf(fp, "node%d:<f0>->node%d:<f0>[color = green];\n", index, spisok.next[index]);

    for (int index = spisok.tail; index != 0; index = spisok.prev[index])
        fprintf(fp, "node%d:<f1>->node%d:<f1>[color = red];\n", index, spisok.prev[index]);
    
    fprintf(fp, "}");

    fclose(fp);
}

//---------------------------------------------------------------------

void List_Destructor(str_spisok spisok)
{
    free(spisok.data);
    free(spisok.next);
    free(spisok.prev);
}