#include <iostream>
using namespace std;

bool canMove(int x, int y)
{
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

void NoOfPos(int curX, int curY, int movei, int chess[][10], int Xmove[], int Ymove[], int N)
{
    int nextX, nextY;

    if (movei > N)
        return;
    //mujhe unique locations nikalni hai after n moves

    //try all next moves from the present postion
    for (int k = 0; k < 8; k++) //find the locations recursively
    {
        nextX = curX + Xmove[k];
        nextY = curY + Ymove[k];

        //pehle check krna hoga ki main is selected move se chal skta hun ya nahi
        //kyunki yeh ho skta hai ki us move ke bad main board se bahar nikal jaun
        //ya phir main us position par pahunch jaun jo pehle se find ho rakhi hai
        //to uske liye ik function bnayenge called 'canMove'

        if (canMove(nextX, nextY))
        {
            chess[nextX][nextY] = movei;
            NoOfPos(nextX, nextY, movei + 1, chess, Xmove, Ymove, N);
        }
    }
    // return;
}
void kahanJaSaktaHun(int curX, int curY, int N)
{

    //pehle main ik board bnaunga aur use ik sentinel value se initiliase krunga
    int chess[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            chess[i][j] = -1;
        }

    //initially wo knight curX,curY pr hain
    chess[curX][curY] = 0;
    //knight in values se horizontally aur vertically chal skta hai
    int Xmove[] = {2, 1, 2, -1, -2, 1, -2, -1};
    int Ymove[] = {1, 2, -1, 2, 1, -2, -1, -2};
    int count = 0;
    NoOfPos(curX, curY, 1, chess, Xmove, Ymove, N);
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (chess[i][j] == N)
                    count++;
                cout << chess[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << count;
    }
}

int main()
{
    int curX, curY, N;
    cin >> curX >> curY >> N;

    kahanJaSaktaHun(curX - 1, curY - 1, N);
}