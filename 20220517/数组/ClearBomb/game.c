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
//     printf("请输入排查雷的坐标x,y:>\n");
//     while (1)
//     {
//         scanf("%d,%d", &x, &y);
//         if (x >= 1 && x <= row && y >= 1 && y <= col)
//         {
//             //坐标合法
//             if (mine[x][y] == '1') //是雷
//             {
//                 printf("很遗憾，你被炸死了\n");
//                 DisplayBoard(mine, row, col);
//                 break;
//             }
//             else if (show[x][y] != '*')
//             {
//                 printf("该坐标已显示，请重新输入:>\n");
//             }
//             else //不是雷
//             {
//                 //计算x,y坐标周围有几个雷
//                 int count = get_mine_count(mine, x, y);
//                 show[x][y] = count + '0';
//                 DisplayBoard(show, row, col);
//                 win++;
//                 if (win < ROW * COL - EASY_COUNT)
//                     printf("请继续输入排查雷的坐标x,y:>\n");
//                 else
//                 {
//                     printf("恭喜你，扫雷成功！\n");
//                     DisplayBoard(mine, row, col);
//                     break;
//                 }
//             }
//         }
//         else
//         {
//             printf("输入坐标非法，请重新输入:>\n");
//         }
//     }
// }

//
void NoBombSquare(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
    int count = get_mine_count(mine, x, y);
    if (count == 0) //此坐标为零，进行递归
    {
        show[x][y] = '0';
        for (int i = x - 1; i <= x + 1; i++)
        {
            if (i > 0 && i <= row) //不能越界--x
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (j > 0 && j <= col && !(i == x && j == y) && show[i][j] == '*') //不能越界--y 且 不递归自身 且不重复递归
                    {
                        NoBombSquare(mine, show, row, col, i, j);
                    }
                }
            }
        }
    }
    else //此坐标不为零，递归尽头
    {
        show[x][y] = '0' + count;
    }
}

//返回1表示游戏结束，返回0表示未结束
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
    printf("请输入排查雷的坐标x,y:>\n");
    while (1)
    {
        scanf("%d,%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            int win = 0;
            //坐标合法
            if (mine[x][y] == '1') //是雷
            {
                printf("很遗憾，你被炸死了\n");
                DisplayBoard(mine, row, col);
                break;
            }
            else if (show[x][y] != '*')
            {
                printf("该坐标已显示，请重新输入:>\n");
            }
            else //不是雷
            {
                NoBombSquare(mine, show, row, col, x, y);
                DisplayBoard(show, row, col);
                win = IsWin(show, row, col);
                if (win == 1)
                {
                    printf("恭喜你，扫雷成功！\n");
                    DisplayBoard(mine, row, col);
                    break;
                }
                printf("请输入排查雷的坐标x,y:>\n");
            }
        }
        else
        {
            printf("输入坐标非法，请重新输入:>\n");
        }
    }
}
