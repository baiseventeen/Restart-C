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
//         // 1.��ӡһ�е�����
//         printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//         // 2.��ӡ�ָ���
//         if (i != 2)
//             printf("---|---|---\n");
//     }
// }

//�Ż�����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        //��ӡһ������
        for (int j = 0; j < col; j++)
        {
            if (j < col - 1)
                printf(" %c |", board[i][j]);
            else
                printf(" %c ", board[i][j]);
        }
        printf("\n");
        //��ӡ�ָ���
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
    printf("����ߣ�������Ҫ�µ�������x,y:\n");
    while (1)
    {
        scanf("%d,%d", &x, &y);
        //�жϺ�������Ϸ���
        if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("�����������ӣ�����������:\n");
            }
        }
        else
        {
            printf("����Ƿ�������������:\n");
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
    printf("�����ߣ��µ�����Ϊ\n%d,%d\n", x + 1, y + 1);
}

//����1��ʾ����
//����0��ʾû��
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
    //�жϺ�
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    //�ж���
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }
    }
    //�����Խ���
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
    {
        return board[2][0];
    }
    //�ж��Ƿ�ƽ��
    if (1 == IsFull(board, ROW, COL))
    {
        return 'Q';
    }
    return 'C';
}