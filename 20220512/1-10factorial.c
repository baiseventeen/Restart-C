#include <stdio.h>
#include <windows.h>

// 求1-10的阶乘之和
// 2022-05-12

int main()
{
    int ret = 0;
    int temp = 1;
    for (int i = 1; i <= 10; i++)
    {
        temp *= i;
        ret += temp;
    }
    printf("%d\n", ret);
    system("pause");
    return 0;
}