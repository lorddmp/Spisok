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
};

void Vstavka(str_spisok* spisok, int index, int value);

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


    return 0;
}

void Vstavka(str_spisok* spisok, int index, int value)
{
    spisok->data[spisok->free] = value;

    spisok->next[spisok->free] = spisok->next[index];
    spisok->next[index] = spisok->free;



    int temp_prev = spisok->prev[index];
}