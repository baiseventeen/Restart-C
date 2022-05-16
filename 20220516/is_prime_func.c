#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// 打印100-200之间的素数
// 2022-5-16

//是素数输出1， 不是素数输出0
int is_prime(int num)
{
    int i = 0;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    for (int i = 101; i < 200; i += 2)
    {
        if (is_prime(i) == 1)
        {
            printf("%d ", i);
        }
    }
    system("pause");
    return 0;
}