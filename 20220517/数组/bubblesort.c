#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ð������
// 2022-5-17

void bubble_sort(int arr[], int sz)
{
    int temp = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        int flag = 1;
        //ÿһ��ð������
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0; //�������򲢲�����
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
    //��arr���������ĳ�����
    //�൱�ڴ���&arr[0]
    bubble_sort(arr, sz); //ð��������
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    system("pause");
    return 0;
}