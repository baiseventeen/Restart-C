#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    char input[10] = {0};
    system("shutdown -s -t 60");
again:
    printf("���Խ���һ�����ڹػ����������룺����������ȡ���ػ���\n�����룺>");
    scanf("%s", input);
    if (0 == strcmp(input, "������"))
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }
    system("pause");
    return 0;
}