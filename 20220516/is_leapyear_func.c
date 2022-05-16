#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//打印1000-2000之间的闰年
// 2022-5-16

int is_leapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    for (int year = 1000; year <= 2000; year++)
    {
        if (is_leapyear(year) == 1)
        {
            printf("%d ", year);
        }
    }
    system("pause");
    return 0;
}