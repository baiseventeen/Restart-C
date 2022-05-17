#include "game.h"

//������������Ϸ
// 2022-5-17

//    |   |
// ---|---|---
//    |   |
// ---|---|---
//    |   |

//������Ϸ���㷨ʵ��
void game()
{
    char ret = 0;
    //����board - ����������
    char board[ROW][COL] = {0}; //ȫ���ո�
    //��ʼ������
    InitBoard(board, ROW, COL);
    //��ӡ����
    DisplayBoard(board, ROW, COL);
    //����
    while (1)
    {
        //�������
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //�ж���Ӯ
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        //��������
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //�ж���Ӯ
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
    {
        printf("���Ӯ��\n");
    }
    else if (ret == '#')
    {
        printf("����Ӯ��\n");
    }
    else
    {
        printf("ƽ�֣�\n");
    }
}

void menu()
{
    printf("***********************************\n");
    printf("******1.��ʼ��Ϸ   0.�˳���Ϸ******\n");
    printf("***********************************\n");
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
            printf("�˳���Ϸ\n");
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