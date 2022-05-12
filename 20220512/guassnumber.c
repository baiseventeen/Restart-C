#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

//猜数字游戏
// 1.电脑生成一个随机数
// 2.猜数字
// 2022-05-12

void menu()
{
    printf("***********************************\n");
    printf("******    1.play  0.exit    *******\n");
    printf("***********************************\n");
}

void game()
{
    int ret = 0;
    int input = 0;
    ret = rand() % 100 + 1;
    // printf("%d\n", ret);
    while (1)
    {
        printf("请猜数字：");
        scanf("%d", &input);
        if (input > ret)
        {
            printf("猜大了\n");
        }
        else if (input < ret)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("猜对了！！\n");
            break;
        }
    }
}

int main()
{
    int input = 1;
    srand((unsigned int)time(NULL));
    while (input)
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("请重新选择\n");
            break;
        }
    }
    system("pause");
    return 0;
}