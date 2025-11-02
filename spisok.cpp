#include <stdio.h>
#include <stdlib.h>
#include "spisok.h"

#define SIZE_DATA 30

int main()
{
    int* data = {};
    str_spisok spisok;
    spisok.data = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.next = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.prev = (int*)calloc(SIZE_DATA, sizeof(int));

    if (spisok.data == NULL)
    {
        printf("CALLOC ERROR");
        return 1;
    }

    if (spisok.next == NULL)
    {
        printf("CALLOC ERROR");
        return 1;
    }

    if (spisok.prev == NULL)
    {
        printf("CALLOC ERROR");
        return 1;
    }

    for (int i = 2; i < SIZE_DATA - 1; i++)
    {
        spisok.next[i] = -1;
        spisok.prev[i] = -1;
    }

    for (int i = 1; i != 0; i = spisok.next[i])
        printf("%d ", spisok.data[i]);

    return 0;
}

void Vstavka(str_spisok* spisok, int index, int value)
{
    spisok->data[spisok->free] = value;

    spisok->next[spisok->free] = spisok->next[index];
    spisok->next[index] = spisok->free;

}