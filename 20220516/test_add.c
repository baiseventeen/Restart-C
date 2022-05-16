#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "add.h"
int main()
{
    int a = 10;
    int b = 20;
    int sum = 0;
    //º¯Êıµ÷ÓÃ
    sum = Add(a, b);
    printf("%d\n", sum);
    system("pause");
    return 0;
}