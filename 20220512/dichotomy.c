#include <stdio.h>
#include <windows.h>

// 二分法
// 2022-05-12

int main()
{
    int arr[] = {1, 2, 5, 7, 9, 12, 64, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = size - 1;
    int n;
    scanf("%d", &n);
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == n)
        {
            printf("找到啦！arr[%d]\n", left);
            break;
        }
        else if (n < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left > right)
    {
        printf("坏了，没找到\n");
    }
    system("pause");
    return 0;
}