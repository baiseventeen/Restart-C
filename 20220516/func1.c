#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    char arr[] = "hello world";
    memset(arr, '*', 5);
    printf("%s\n", arr);
    system("pause");
    return 0;
}