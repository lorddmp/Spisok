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

void Print_Spisok(str_spisok spisok);

int main()
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

    IF_ERROR_CALLOC(spisok.data);
    IF_ERROR_CALLOC(spisok.next);
    IF_ERROR_CALLOC(spisok.prev);

    for (int i = 1; i < SIZE_DATA - 1; i++)
        spisok.next[i] = i + 1;

    for (int i = 2; i < SIZE_DATA - 1; i++)
        spisok.prev[i] = -1;

    Print_Spisok(spisok);
    Vstavka(&spisok, 10, 40);
    Print_Spisok(spisok);
    Vstavka(&spisok, 0, 10);
    Print_Spisok(spisok);
    // Vstavka(&spisok, 2, 20);
    // Print_Spisok(spisok);
    // Vstavka(&spisok, 2, 30);
    // Print_Spisok(spisok);
    // Vstavka(&spisok, 0, 30);
    // Print_Spisok(spisok);

    free(spisok.data);
    free(spisok.next);
    free(spisok.prev);

    return 0;
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

    printf("(0) ");

    for (int i = spisok.head; i != 0; i = spisok.next[i])
        printf("%d ", spisok.data[i]);

    printf("\n\n----------------------------------\n\n");
}