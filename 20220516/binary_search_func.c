#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

// 二分查找
// 在一个有序数组中查找某个具体的数
// 如果找到了返回下标，找不到返回-1
// 2022-5-16

// 本质上arr是个指针
int binary_search(int arr[], int k, int sz)
{
    //算法的实现
    int left = 0;
    int right = sz - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (k < arr[mid])
        {
            right = mid - 1;
        }
        else if (k > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    //传递过去的数组首元素的地址
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = binary_search(arr, k, sz);
    if (ret == -1)
    {
        printf("没找到\n");
    }
    else
    {
        printf("找到了，下标为%d\n", ret);
    }
    system("pause");
    return 0;
}