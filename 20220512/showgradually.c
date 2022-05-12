#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// 逐步显示字符串
// 2022-05-12

// int main()
// {
//     char str[] = "welcome to shandong!!!!!";
//     for (int i = 0; i <= strlen(str) / 2; i++) //打印字符串
//     {
//         for (int j = 0; j < i; j++) //控制前面字符的逐步显示
//         {
//             printf("%c", str[j]);
//         }
//         for (int k = 0; k < strlen(str) - 2 * i; k++) // 控制井字数量
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
    // sizeof 比 strlen 多1， 因为sizeof算'\0'
    int right = strlen(str1) - 1;
    //思想str1替换str2
    //打印str2
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