#include <game.h>

void InitBoard(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// void DisplayBoard(char board[ROW][COL], int row, int col)
// {
//     int i = 0;
//     for (i = 0; i < row; i++)
//     {
//         // 1.打印一行的数据
//         printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//         // 2.打印分隔符
//         if (i != 2)
//             printf("---|---|---\n");
//     }
// }

//优化代码
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        //打印一行数据
        for (int j = 0; j < col; j++)
        {
            if (j < col - 1)
                printf(" %c |", board[i][j]);
            else
                printf(" %c ", board[i][j]);
        }
        printf("\n");
        //打印分隔行
        if (i < row - 1)
        {
            for (int j = 0; j < col; j++)
            {
                if (j < col - 1)
                    printf("---|", board[i][j]);
                else
                    printf("---", board[i][j]);
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家走，请输入要下的坐标下x,y:\n");
    while (1)
    {
        scanf("%d,%d", &x, &y);
        //判断横纵坐标合法性
        if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("该坐标有棋子，请重新输入:\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入:\n");
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
    printf("电脑走，下的坐标为\n%d,%d\n", x + 1, y + 1);
}

//返回1表示满了
//返回0表示没满
int IsFull(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
    //判断横
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    //判断纵
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }
    }
    //两个对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
    {
        return board[2][0];
    }
    //判断是否平局
    if (1 == IsFull(board, ROW, COL))
    {
        return 'Q';
    }
    return 'C';
}