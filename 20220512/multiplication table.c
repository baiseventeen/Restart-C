#include <stdio.h>
#include <windows.h>

//��ӡ�žų˷���
// 2022-05-12

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%.4d ", i, j, i * j);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}