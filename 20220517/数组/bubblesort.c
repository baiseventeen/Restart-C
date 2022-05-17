#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//冒泡排序
// 2022-5-17

void bubble_sort(int arr[], int sz)
{
    int temp = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        int flag = 1;
        //每一趟冒泡排序
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0; //本趟排序并不有序
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    //对arr进行排序，拍成升序
    //相当于传的&arr[0]
    bubble_sort(arr, sz); //冒泡排序函数
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    system("pause");
    return 0;
}