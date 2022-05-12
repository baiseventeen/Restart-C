#include <stdio.h>
#include <windows.h>

// ÇónµÄ½×³Ë
// 2022-05-12

int main()
{
    int n;
    while ((scanf("%d", &n)) != EOF)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= i;
        }
        printf("%d!=%d\n", n, res);
    }
    system("pause");
    return 0;
}