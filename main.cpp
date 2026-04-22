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
    str_spisok spisok;
    Init_Spisok(&spisok);

    // Write_Spisok(spisok);
    // Data_Vstavka(&spisok, 0, 40);
    // Write_Spisok(spisok);
    // Data_Vstavka(&spisok, 0, 10);
    // Write_Spisok(spisok);
    // List_Delete(&spisok, 2);
    // Write_Spisok(spisok);
    // Data_Vstavka(&spisok, 1, 30);
    // Write_Spisok(spisok);
    // Data_Vstavka(&spisok, 0, 30);
    // Write_Spisok(spisok);

    Write_Spisok(spisok);
    List_Vstavka(&spisok, 0, 40);
    Write_Spisok(spisok);
    List_Vstavka(&spisok, 0, 10);
    Write_Spisok(spisok);
    List_Delete(&spisok, 2);
    Write_Spisok(spisok);
    List_Vstavka(&spisok, 1, 30);
    Write_Spisok(spisok);
    List_Vstavka(&spisok, 0, 30);
    Write_Spisok(spisok);

    List_Destructor(spisok);

    return 0;
}