#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

//��������Ϸ
// 1.��������һ�������
// 2.������
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
        printf("������֣�");
        scanf("%d", &input);
        if (input > ret)
        {
            printf("�´���\n");
        }
        else if (input < ret)
        {
            printf("��С��\n");
        }
        else
        {
            printf("�¶��ˣ���\n");
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
        printf("��ѡ��");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("������ѡ��\n");
            break;
        }
    }
    system("pause");
    return 0;
}