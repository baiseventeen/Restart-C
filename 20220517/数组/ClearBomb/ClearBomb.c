
#include "game.h"

void menu()
{
    printf("***********************************\n");
    printf("*              ɨ��               *\n");
    printf("***********************************\n");
    printf("*          1. ��ʼ��Ϸ            *\n");
    printf("*          0. �˳���Ϸ            *\n");
    printf("***********************************\n");
}

void game()
{
    //�׵���Ϣ�洢
    // 1.���úõ��׵���Ϣ
    char mine[ROWS][COLS] = {0};
    // 2.�Ų�����׵���Ϣ
    char show[ROWS][COLS] = {0};
    //��ʼ��
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //������
    SetMine(mine, ROW, COL);
    //��ӡ����
    DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //ɨ��
    FindMine(mine, show, ROW, COL);
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ�ɹ�\n");
            break;
        default:
            printf("������ѡ��\n");
            break;
        }
    } while (input);
}

int main()
{
    test();
    system("pause");
    return 0;
}