#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    // 좌우상하
    int dr[4] = {0,0,1,-1};
    int dc[4] = {-1,1,0,0};
    enum Dir { left, right, up, down };
    int r = 0, c = 0;
    int rStart = -board[1] / 2;
    int rEnd = board[1] / 2;
    int cStart = -board[0] / 2;
    int cEnd = board[0] / 2;
    
    for (auto& key : keyinput)
    {
        int nr = r, nc = c;
        if (key == "left") nc += dc[left];
        else if (key == "right") nc += dc[right];
        else if (key == "up") nr += dr[up];
        else nr += dr[down];
        
        if (nr >= rStart && nr <= rEnd && nc >= cStart && nc <= cEnd)
        {
            r = nr;
            c = nc;
        }
    }
    return {c, r};
}