#include <bits/stdc++.h>
using namespace std;

struct coord
{
    int x, y;
};

int solution(int m, int n, vector<string> board) {
    // m이 행, n이 열
    int answer = 0;
    while (1)
    {
        // 지울 곳 체크했다가 한꺼번에 지우고 카운팅 하기
        bool continued = false;
        vector<vector<int>> willDelete(m, vector<int>(n));
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] != '.' &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j + 1])
                {
                    continued = true;
                    willDelete[i][j] = true;
                    willDelete[i + 1][j] = true;
                    willDelete[i][j + 1] = true;
                    willDelete[i + 1][j + 1] = true;
                }
            }
        }

        if (continued == false) break;

        for (int i=0;i<m;i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (willDelete[i][j])
                {
                    board[i][j] = '.';
                    ++answer;
                }
            }
        }

        // 블록 내리기
        for (int x = m - 1; x >= 0; x--)
        {
            for (int y = 0; y < n; y++)
            {
                if (board[x][y] == '.')
                {
                    int dest = x - 1;
                    while (dest >= 0 && board[dest][y] == '.')
                    {
                        --dest;
                    }
                    if (dest < 0) ++dest;

                    int destDown = dest + 1;
                    while (destDown < m && board[destDown][y] == '.')
                    {
                        ++destDown;
                    }
                    --destDown;

                    board[destDown][y] = board[dest][y];
                    board[dest][y] = '.';
                }
            }
        }
    }
    return answer;
}