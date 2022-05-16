#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//找两个数的最大值
// 2022-05-16

int get_max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int a = 10;
    int b = 20;
    int max = get_max(a, b);
    printf("%d\n", max);
    system("pause");
    return 0;
}