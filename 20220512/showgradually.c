#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// ����ʾ�ַ���
// 2022-05-12

// int main()
// {
//     char str[] = "welcome to shandong!!!!!";
//     for (int i = 0; i <= strlen(str) / 2; i++) //��ӡ�ַ���
//     {
//         for (int j = 0; j < i; j++) //����ǰ���ַ�������ʾ
//         {
//             printf("%c", str[j]);
//         }
//         for (int k = 0; k < strlen(str) - 2 * i; k++) // ���ƾ�������
//         {
//             printf("#");
//         }
//         for (int j = strlen(str) - i; j < strlen(str); j++)
//         {
//             printf("%c", str[j]);
//         }
//         printf("\n");
//     }
//     system("pause");
//     return 0;
// }

int main()
{
    char str1[] = "welcome to shandong!!!!!";
    char str2[] = "########################";
    int left = 0;
    // sizeof �� strlen ��1�� ��Ϊsizeof��'\0'
    int right = strlen(str1) - 1;
    //˼��str1�滻str2
    //��ӡstr2
    while (left <= right)
    {
        str2[left] = str1[left];
        str2[right] = str1[right];
        printf("%s\n", str2);
        Sleep(1000);
        system("cls");
        left++;
        right--;
    }
    system("pause");
    return 0;
}