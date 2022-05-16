#include <stdio.h>
#include <stdlib.h>

int HanNuo(int n, char a, char b, char c)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int one = HanNuo(n - 1, a, c, b);
        int two = HanNuo(n - 1, b, a, c);
        return one + two + 1;
    }
}

int main()
{
    int num = 0;
    num = HanNuo(4, 'a', 'b', 'c');
    printf("%d", num);
    system("pause");
    return 0;
}