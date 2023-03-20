#include <string>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<string> board) {
    int sizeR = board.size();
    int sizeC = board[0].size();

    bool findFlag = false;
    int rx = 0, ry = 0;

    for (int x=0; x<sizeR && !findFlag; x++)
    {
        for (int y=0; y<sizeC && !findFlag; y++)
        {
            if (board[x][y] == 'R')
            {
                rx = x;
                ry = y;
                findFlag = true;
            }
        }
    }

    int answer = 1e9;
    int dr[4] = { 0,0,1,-1 };
    int dc[4] = { 1,-1,0,0 };
    vector<vector<int>> trace(sizeR, vector<int>(sizeC, -1));

    function<void(int, int, int)> dfs = [&](int depth, int r, int c)
    {
        if (board[r][c] == 'G')
        {
            answer = min(answer, depth);
            return;
        }
        else if (depth > answer)
            return;
        else if (trace[r][c] > answer)
            return;

        for (int i=0; i<4; i++)
        {
            int nr = r;
            int nc = c;

	        while (true)
	        {
                nr += dr[i];
                nc += dc[i];
                if (nr < 0 || nr >= sizeR || nc < 0 || nc >= sizeC ||
                    board[nr][nc] == 'D')
                {
                    nr -= dr[i];
                    nc -= dc[i];
                    break;
                }
	        }

            if (trace[nr][nc] == -1 || depth < trace[nr][nc])
            {
                trace[nr][nc] = depth + 1;
                dfs(depth + 1, nr, nc);
            }
        }
    };
    trace[rx][ry] = 0;
    dfs(0, rx, ry);

    return answer == 1e9 ? -1 : answer;
}