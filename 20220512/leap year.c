#include <stdio.h>
#include <windows.h>

//´òÓ¡ÈòÄê
// 2022-05-12

int main()
{
    for (int year = 1000; year <= 2022; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            printf("%d ", year);
        }
    }
    system("pause");
    return 0;
}