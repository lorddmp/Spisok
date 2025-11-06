#include <stdio.h>
#include <stdlib.h>
#include "spisok.h"

void Vstavka(str_spisok* spisok, int index, int value)
{
    int free = spisok->next[spisok->free];

    if (index == 0)
        spisok->head = spisok->free;

    spisok->data[spisok->free] = value;
    spisok->next[spisok->free] = spisok->next[index];
    spisok->next[index] = spisok->free;

    spisok->free = free;
}