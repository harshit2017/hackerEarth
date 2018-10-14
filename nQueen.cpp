#include <iostream>
using namespace std;

void print(int board[][10], int n = 10)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int board[][10], int x, int y,int N)
{
    //check along the col
    for (int i = 0; i < N; i++)
    {
        if (board[i][y] == 1)
            return false;
    }
    //check along left diagonal
    int i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        --j, --i;
    }
    //check along the right diagonal
    i = x - 1, j = y + 1;
    while (i >= 0 && j < N)
    {
        if (board[i][j] == 1)
            return false;
        --i, ++j;
    }
    return true;
}

bool queen(int board[][10], int cRow,int N)
{
    if (cRow == N)
    {

        return true;
    }
    for (int col = 0; col < N; col++)
    {
        if (canPlace(board, cRow, col,N) == true)
        {
            board[cRow][col] = 1;

            bool ask = queen(board, cRow + 1,N);
            if (ask == true)
            {
                return true;
            }

            board[cRow][col] = 0;
        }
    }

    return false;
}
int main()
{
    int N;
    cin >> N;
    int board[10][10] = {};
    if (queen(board, 0,N))
        print(board, N);
    else
        cout << "Not possible\n";
}