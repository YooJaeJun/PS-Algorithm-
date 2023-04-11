#include <string>
#include <vector>
#include <deque>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    int sizeR = maps.size();
    int sizeC = maps[0].size();
    deque<deque<bool>> visited(sizeR, deque<bool>(sizeC));
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    function<void(int, int, int&)> dfs = [&](int x, int y, int& sum)
    {
        for (int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=sizeR || ny<0 || ny>=sizeC || 
                maps[nx][ny] == 'X' ||
                visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            sum += maps[nx][ny] - '0';
            dfs(nx, ny, sum);
        }
    };
    
    vector<int> answer;
    
    for (int r=0; r<sizeR; r++)
    {
        for (int c=0; c<sizeC; c++)
        {
            if (maps[r][c] != 'X' && 
                visited[r][c] == false)
            {
                int sum = maps[r][c] - '0';
                visited[r][c] = true;
                dfs(r, c, sum);
                answer.push_back(sum);
            }
        }
    }
    
    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}