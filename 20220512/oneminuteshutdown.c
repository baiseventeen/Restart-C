#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    char input[10] = {0};
    system("shutdown -s -t 60");
again:
    printf("电脑将在一分钟内关机，必须输入：我是猪，才能取消关机！\n请输入：>");
    scanf("%s", input);
    if (0 == strcmp(input, "我是猪"))
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