#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    return my_strlen(str + 1) + 1; // str++����++str����
}
//�Ѵ��»�С
// my_strlen("1231")
// 1 + my_strlen("231")
// 1 + 1 + my_strlen("31")
// 1 + 1 + 1 + my_strlen("1")
// 1 + 1 + 1 + 1 + my_strlen("")
// 1 + 1 + 1 + 1 + 0

int main()
{
    char str[] = "1231";
    //   int len = strlen(str);
    int len = my_strlen(str); //���鴫�Σ�����ȥ����Ԫ�ص�ַ
    printf("%d", len);
    system("pause");
    return 0;
}