#include "spisok.h"

#define IF_ERROR_CALLOC(arg)                \
do                                          \
{                                           \
    if (arg == NULL)                        \
    {                                       \
        printf("CALLOC ERROR\n");           \
        return 1;                           \
    }                                       \
} while (0)

int main()
{
    str_spisok spisok = Init_Spisok();
    IF_ERROR_CALLOC(spisok.data);
    IF_ERROR_CALLOC(spisok.next);
    IF_ERROR_CALLOC(spisok.prev);

    for (int i = 1; i < SIZE_DATA - 1; i++)
        spisok.next[i] = i + 1;

    for (int i = 2; i < SIZE_DATA - 1; i++)
        spisok.prev[i] = -1;

    Print_Spisok(spisok);
    LVstavka(&spisok, 0, 40);
    Print_Spisok(spisok);
    LVstavka(&spisok, 0, 10);
    Print_Spisok(spisok);
    LDelete(&spisok, 2);
    Print_Spisok(spisok);
    LVstavka(&spisok, 2, 30);
    Print_Spisok(spisok);
    LVstavka(&spisok, 0, 30);
    Print_Spisok(spisok);

    free(spisok.data);
    free(spisok.next);
    free(spisok.prev);

    return 0;
}