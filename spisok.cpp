#include <stdio.h>
#include <stdlib.h>
#include "spisok.h"

int Find_Index_In_Next(str_spisok* spisok, int* counter, int* index_next);

int Find_Index_In_Next(str_spisok* spisok, int* counter, int* index_next)
{
    if (spisok->head == 0)
        *counter = 0;

    if (*counter > 0)
    {
        *index_next = spisok->next[*index_next];            
        (*counter)--;
        Find_Index_In_Next(spisok, counter, index_next);
    }
    
    return *index_next;
}

str_spisok Init_Spisok(void)
{
    str_spisok spisok;
    spisok.data = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.next = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.prev = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.free = 1;
    spisok.head = 0;                                            //индекс первого элемента списка в data
    spisok.tail = 0;                                            //индекс последнего элемента списка в data
    spisok.size = 0;                                            //количество элементов в списке (можно использовать как индикатор для tail или
                                                                //чтобы после индекса больше чем элементов в data элемент ставился в конец)
    return spisok;
}

void LVstavka(str_spisok* spisok, int index, int value)
{
    int free = spisok->next[spisok->free];

    spisok->data[spisok->free] = value;

    int start_index = 0;                                                        //индекс в next, где лежит индекс первого элемента списка в data
    int counter = index;
    int index_next = Find_Index_In_Next(spisok, &counter, &start_index);        //возвращает индекс в next, куда надо записать индекс нового элемента и откуда взять индекс следующего после него
                                                                                //а индекс следующего элемента - это индекс элемента, ДО которого вставили новый элемент
    spisok->prev[spisok->free] = spisok->prev[spisok->next[index_next]];
    spisok->prev[spisok->next[index_next]] = spisok->free;

    spisok->next[spisok->free] = spisok->next[index_next];
    spisok->next[index_next] = spisok->free;

    if (index == 0)
        spisok->head = spisok->free;

    spisok->free = free;

    // if (index >= spisok->size)
    //     spisok->tail = index_next;

    // spisok->size++;
}

void LDelete(str_spisok* spisok, int index)
{
    int start_index = 0;
    int counter = index;
    int index_next = Find_Index_In_Next(spisok, &counter, &start_index);
    int del_index = spisok->prev[spisok->next[index_next]];

    spisok->data[del_index] = 0;

    if (del_index == spisok->head)
        spisok->head = spisok->next[del_index];

    // else if (del_index == spisok->tail)
    //     spisok->tail = spisok->prev[del_index];

    spisok->next[spisok->prev[del_index]] = spisok->next[del_index];
    spisok->prev[spisok->next[del_index]] = spisok->prev[del_index];
    spisok->prev[del_index] = -1;
    spisok->next[del_index] = spisok->free;

    spisok->free = del_index;
    // spisok->free--;
}

void Print_Spisok(str_spisok spisok)
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