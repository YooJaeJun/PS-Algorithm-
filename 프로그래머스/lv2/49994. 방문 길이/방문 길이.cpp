#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
    int n = 11;
    vector<vector<int>> nodes(n, vector<int>(n));
    bool visited[11][11][11][11] = {false, };
    vector<int> dx;
    vector<int> dy;
        
    for(auto elem : dirs) {
        switch(elem) {
            case 'L':
                dx.push_back(0);
                dy.push_back(-1);
                break;
            case 'R':
                dx.push_back(0);
                dy.push_back(1);
                break;
            case 'U':
                dx.push_back(-1);
                dy.push_back(0);
                break;
            case 'D':
                dx.push_back(1);
                dy.push_back(0);
                break;
        }
    }
    
    int ans = 0;
    int x = 5, y = 5;
    int nx = x, ny = y;
    for(int i=0;i!=dirs.size();i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) {
            nx -= dx[i];
            ny -= dy[i];
            continue;
        }
        if(visited[x][y][nx][ny] == false || visited[nx][ny][x][y] == false) {
            ans++;
            visited[x][y][nx][ny] = true;
            visited[nx][ny][x][y] = true;
        }
        x = nx;
        y = ny;
    }
    return ans;
}