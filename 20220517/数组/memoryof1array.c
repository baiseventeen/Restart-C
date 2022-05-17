#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一维数组在内存的存储
// 2022-5-17

int main()
{
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int sz = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < sz; i++)
    {
        printf("arr[%d] = %p\n", i, &arr2[i]);
    }
    system("pause");
    return 0;
}