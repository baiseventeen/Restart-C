#include <stdio.h>
#include <windows.h>

// getchar学习
// 2022-05-12

// int main()
// {
//     int ch = 0;
//     while((ch = getchar()) != EOF)
//     {
//         putchar(ch);
//     }
//     system("pause");
//     return 0;
// }

// int main()
// {
//     int ret = 0;
//     char password[20] = {0};
//     printf("请输入密码：>");
//     scanf("%s", password);
//     //2.getchar();吃走'\n'
//     printf("请确认(Y/N):>");
//     //1.程序从这里直接跳步
//     //1.缓冲区还剩余一个'\n'
//     ret = getchar();
//     ret == 'Y' ? printf("确认成功\n") : printf("放弃确认\n");
//     system("pause");
//     return 0;
// }

int main()
{
    int ret = 0;
    char password[20] = {0};
    printf("请输入密码：>");
    scanf("%s", password);
    while (getchar() != '\n')
    {
    }
    printf("请确认(Y/N):>");
    ret = getchar();
    ret == 'Y' ? printf("确认成功\n") : printf("放弃确认\n");
    system("pause");
    return 0;
}