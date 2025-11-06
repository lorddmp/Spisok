#include "spisok.h"

int main()
{
    int* data = {};
    str_spisok spisok;
    spisok.data = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.next = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.prev = (int*)calloc(SIZE_DATA, sizeof(int));
    spisok.free = 1;
    spisok.head = 1;

    if (spisok.data == NULL)
    {
        printf("CALLOC ERROR\n");
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

    for (int i = 1; i < SIZE_DATA - 1; i++)
        spisok.next[i] = i + 1;

    // for (int i = 2; i < SIZE_DATA - 1; i++)
    //     spisok.prev[i] = -1;

    Vstavka(&spisok, 0, 40);
    Vstavka(&spisok, 1, 20);
    Vstavka(&spisok, 2, 30);
    Vstavka(&spisok, 0, 10);

    printf("data: ");
    for (int i = 0; i < SIZE_DATA; i++)
        printf("%d ", spisok.data[i]);
    printf("\n");

    printf("next: ");
    for (int i = 0; i < SIZE_DATA; i++)
        printf("%d ", spisok.next[i]);
    printf("\n");

    // printf("prev: ");
    // for (int i = 0; i < SIZE_DATA; i++)
    //     printf("%d ", spisok.next[i]);
    // printf("\n");

    for (int i = spisok.head; i != 0; i = spisok.next[i])
        printf("%d ", spisok.data[i]);

    return 0;
}