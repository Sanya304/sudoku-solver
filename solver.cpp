#include <iostream>
#include <math.h>
using namespace std;
void print(int board[][9], int bs)
{
    for (int i = 0; i < bs; i++)
    {
        for (int j = 0; j < bs; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isvalid(int b[][9], int r, int c, int n, int bs)
{
    for (int i = 0; i < bs; i++)
    {
        if ((b[r][i] == n) || (b[i][c] == n))
        {
            return false;
        }
    }
    int sqv = sqrt(bs);
    int sriosm = r - (r % sqv);
    int sciosm = c - (c % sqv);
    for (int i = sriosm; i < sriosm + sqv; i++)
    {
        for (int j = sciosm; j < sciosm + sqv; j++)
        {
            if (b[i][j] == n)
            {
                return false;
            }
        }
    }
    return true;
}
bool ss(int b[][9], int r, int c, int bs)
{
    if (r == bs)
    {
        print(b, bs);
        return true;
    }
    if (c == bs)
    {
        return ss(b, r + 1, 0, bs);
    }
    if (b[r][c] != 0)
    {
        return ss(b, r, c + 1, bs);
    }
    for (int i = 0; i <= 9; i++)
    {
        if (isvalid(b, r, c, i, bs))
        {
            b[r][c] = i;
            bool sa = ss(b, r, c + 1, bs);
            if (sa)
            {
                return true;
            }
            b[r][c] = 0;
        }
    }
    return false;
}
int main()
{
    int bs = 9;
    int b[9][9] = {
        {0, 0, 7, 1, 0, 0, 0, 6, 0},
        {1, 0, 5, 2, 0, 8, 0, 0, 0},
        {6, 0, 0, 0, 0, 7, 1, 2, 0},
        {3, 1, 2, 4, 0, 5, 0, 0, 8},
        {0, 0, 6, 0, 9, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 1},
        {0, 0, 1, 0, 0, 4, 9, 8, 6},
        {8, 0, 3, 9, 0, 6, 0, 0, 0},
        {0, 6, 0, 0, 8, 2, 7, 0, 3}};
    ss(b, 0, 0, bs);
}