#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ε�¼��ʧ�ܽ�ֹ��¼
// 2022-05-12

int main()
{
    char password[20] = {0};
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("���������룺");
        scanf("%s", password);
        if (strcmp(password, "123456") == 0) //!!!!!!�ȺŲ��������Ƚ��ַ����Ƿ���ȣ�Ӧ����strcmp()
        {
            printf("��¼�ɹ�\n");
            break;
        }
        else
        {
            printf("�������\n");
        }
    }
    if (i == 3)
    {
        printf("��������������˳�����\n");
    }
    system("pause");
    return 0;
}