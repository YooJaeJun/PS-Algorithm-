#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    // 좌 우 상 하 좌상 우상 좌하 우하
    int dr[8] = {0,0,-1,1,-1,-1,1,1};
    int dc[8] = {-1,1,0,0,-1,1,-1,1};
    
    for (int r=0; r<board.size(); r++)
    {
        for (int c=0; c<board[0].size(); c++)
        {
            if (board[r][c] == 1)
            {
                for (int i=0; i<8; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < board.size() && nc >=0 && nc < board[0].size() &&
                       !board[nr][nc])
                    {
                        board[nr][nc] = 2;
                    }
                }
            }
        }
    }
    
    int answer = 0;
    for (int r=0; r<board.size(); r++)
    {
        for (int c=0; c<board[r].size(); c++)
        {
            if (!board[r][c]) answer++;
        }
    }
    return answer;
}