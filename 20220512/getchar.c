#include <stdio.h>
#include <windows.h>

// getcharѧϰ
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
//     printf("���������룺>");
//     scanf("%s", password);
//     //2.getchar();����'\n'
//     printf("��ȷ��(Y/N):>");
//     //1.���������ֱ������
//     //1.��������ʣ��һ��'\n'
//     ret = getchar();
//     ret == 'Y' ? printf("ȷ�ϳɹ�\n") : printf("����ȷ��\n");
//     system("pause");
//     return 0;
// }

int main()
{
    int ret = 0;
    char password[20] = {0};
    printf("���������룺>");
    scanf("%s", password);
    while (getchar() != '\n')
    {
    }
    printf("��ȷ��(Y/N):>");
    ret = getchar();
    ret == 'Y' ? printf("ȷ�ϳɹ�\n") : printf("����ȷ��\n");
    system("pause");
    return 0;
}