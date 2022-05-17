#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一维数组的使用
// 2022-5-17

int main()
{
    char arr[] = "abcdef";
    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        printf("%c ", arr[i]);
    }

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int sz = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr2[i]);
    }
    system("pause");
    return 0;
}