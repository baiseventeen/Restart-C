#include <stdio.h>
#include <stdlib.h>

//分别打印每位数字
// 2022-5-16

void print1(int num)
{
    if (num != 0)
    {
        print1(num / 10);
        printf("%d ", num % 10);
    }
    else
    {
        return;
    }
}

void print(int num)
{
    if (num > 9)
    {
        print(num / 10);
    }
    printf("%d ", num % 10);
}

int main()
{
    unsigned int num = 0;
    scanf("%d", &num);
    //递归
    print(num);
    system("pause");
    return 0;
}