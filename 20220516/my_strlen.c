#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    return my_strlen(str + 1) + 1; // str++报错，++str可以
}
//把大事化小
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
    int len = my_strlen(str); //数组传参，传过去的首元素地址
    printf("%d", len);
    system("pause");
    return 0;
}