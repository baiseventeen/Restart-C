#include <stdio.h>
#include <windows.h>

// 1-100ÆæÊı
// 2022-05-11

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 1)
        {
            printf("%d ", i);
        }
    }
    system("pause");
    return 0;
}