#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    vector<int> dp(board[0].size() + 2);
    int before = 0, maxn = 0;
    
    for (int i=1; i<=board.size(); i++)
    {
        for (int j=1; j<=board[i - 1].size(); j++)
        {
            int temp = dp[j];
            if (board[i - 1][j - 1])
            {
                dp[j] = min(min(dp[j - 1], before), dp[j]) + 1;
                maxn = max(maxn, dp[j]);
            }
            else
            {
                dp[j] = 0;
            }
            before = temp;
        }
    }

    return maxn * maxn;
}