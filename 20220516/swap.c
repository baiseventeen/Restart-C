#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

// 交换两个数
// 2022-5-16

void swap1(int x, int y)
{
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

void swap2(int *pa, int *pb)
{
    int temp = 0;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    // swap1(a, b);
    swap2(&a, &b);
    printf("%d, %d\n", a, b);
    system("pause");
    return 0;
}