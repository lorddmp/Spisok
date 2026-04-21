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

void Vstavka(str_spisok* spisok, int index, int value)
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
}