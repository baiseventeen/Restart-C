#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    for (int i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    puts("");
    for (int i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        puts("");
    }
    puts("");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % row + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            count += (mine[i][j] - '0');
        }
    }
    return count;
}

// void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
// {
//     int x = 0;
//     int y = 0;
//     int win = 0;
//     printf("�������Ų��׵�����x,y:>\n");
//     while (1)
//     {
//         scanf("%d,%d", &x, &y);
//         if (x >= 1 && x <= row && y >= 1 && y <= col)
//         {
//             //����Ϸ�
//             if (mine[x][y] == '1') //����
//             {
//                 printf("���ź����㱻ը����\n");
//                 DisplayBoard(mine, row, col);
//                 break;
//             }
//             else if (show[x][y] != '*')
//             {
//                 printf("����������ʾ������������:>\n");
//             }
//             else //������
//             {
//                 //����x,y������Χ�м�����
//                 int count = get_mine_count(mine, x, y);
//                 show[x][y] = count + '0';
//                 DisplayBoard(show, row, col);
//                 win++;
//                 if (win < ROW * COL - EASY_COUNT)
//                     printf("����������Ų��׵�����x,y:>\n");
//                 else
//                 {
//                     printf("��ϲ�㣬ɨ�׳ɹ���\n");
//                     DisplayBoard(mine, row, col);
//                     break;
//                 }
//             }
//         }
//         else
//         {
//             printf("��������Ƿ�������������:>\n");
//         }
//     }
// }

//
void NoBombSquare(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
    int count = get_mine_count(mine, x, y);
    if (count == 0) //������Ϊ�㣬���еݹ�
    {
        show[x][y] = '0';
        for (int i = x - 1; i <= x + 1; i++)
        {
            if (i > 0 && i <= row) //����Խ��--x
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (j > 0 && j <= col && !(i == x && j == y) && show[i][j] == '*') //����Խ��--y �� ���ݹ����� �Ҳ��ظ��ݹ�
                    {
                        NoBombSquare(mine, show, row, col, i, j);
                    }
                }
            }
        }
    }
    else //�����겻Ϊ�㣬�ݹ龡ͷ
    {
        show[x][y] = '0' + count;
    }
}

//����1��ʾ��Ϸ����������0��ʾδ����
int IsWin(char show[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (show[i][j] == '*')
            {
                count++;
            }
        }
    }
    if (count == EASY_COUNT)
    {
        return 1;
    }
    return 0;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("�������Ų��׵�����x,y:>\n");
    while (1)
    {
        scanf("%d,%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            int win = 0;
            //����Ϸ�
            if (mine[x][y] == '1') //����
            {
                printf("���ź����㱻ը����\n");
                DisplayBoard(mine, row, col);
                break;
            }
            else if (show[x][y] != '*')
            {
                printf("����������ʾ������������:>\n");
            }
            else //������
            {
                NoBombSquare(mine, show, row, col, x, y);
                DisplayBoard(show, row, col);
                win = IsWin(show, row, col);
                if (win == 1)
                {
                    printf("��ϲ�㣬ɨ�׳ɹ���\n");
                    DisplayBoard(mine, row, col);
                    break;
                }
                printf("�������Ų��׵�����x,y:>\n");
            }
        }
        else
        {
            printf("��������Ƿ�������������:>\n");
        }
    }
}
