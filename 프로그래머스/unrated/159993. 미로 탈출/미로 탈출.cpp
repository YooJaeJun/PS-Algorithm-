#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

int solution(vector<string> maps) {
    int r = maps.size();
    int c = maps[0].size();
    int startX = 0, startY = 0, leverX = 0, leverY = 0, endX = 0, endY = 0;
    
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            switch(maps[i][j])
            {
                case 'S':
                    startX = i;
                    startY = j;
                    break;
                case 'L':
                    leverX = i;
                    leverY = j;
                    break;
                case 'E':
                    endX = i;
                    endY = j;
                    break;
            }
        }
    }
    
    struct Info
    {
        int x;
        int y;
        int depth;
    };
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    deque<deque<bool>> visited(r, deque<bool>(c));
    
    function<void(int, int, int, int, int&)> bfs = 
        [&](int startX, int startY, int endX, int endY, int& path)
    {
        queue<Info> q;
        q.push({startX, startY, 0});
        
        while (q.empty() == false)
        {
            int x = q.front().x;
            int y = q.front().y;
            int depth = q.front().depth;
            if (x == endX && y == endY)
                path = min(path, depth);
            q.pop();
            
            for (int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                    continue;
                if (visited[nx][ny] ||
                    maps[nx][ny] == 'X' ||
                    depth >= path)
                    continue;
                visited[nx][ny] = true;
                q.push({nx, ny, depth + 1});
            }
        }
    };
    
    int path[2] = {INT_MAX,INT_MAX};
    bfs(startX, startY, leverX, leverY, path[0]);
    
    for (int i=0; i<r; i++)
        fill(visited[i].begin(), visited[i].end(), false);
    
    bfs(leverX, leverY, endX, endY, path[1]);
    
    if (path[0] == INT_MAX || path[1] == INT_MAX)
        return -1;
    return path[0] + path[1];
}