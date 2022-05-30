#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int ans = board[0][0];
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[i].size(); j++)
        {
            if (i != 0 && j != 0 && board[i][j] == 1)
            {
                board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
            }
            ans = max(ans, board[i][j]);
        }
    }

    return ans * ans;
}