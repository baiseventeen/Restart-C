#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

// ���ֲ���
// ��һ�����������в���ĳ���������
// ����ҵ��˷����±꣬�Ҳ�������-1
// 2022-5-16

// ������arr�Ǹ�ָ��
int binary_search(int arr[], int k, int sz)
{
    //�㷨��ʵ��
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
    //���ݹ�ȥ��������Ԫ�صĵ�ַ
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = binary_search(arr, k, sz);
    if (ret == -1)
    {
        printf("û�ҵ�\n");
    }
    else
    {
        printf("�ҵ��ˣ��±�Ϊ%d\n", ret);
    }
    system("pause");
    return 0;
}