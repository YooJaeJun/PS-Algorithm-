#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> maps) {
    const int dy[4] = { 1,0,-1,0 };
    const int dx[4] = { 0,1,0,-1 };
    const int m = maps.size();
    const int n = maps[0].size();

    vector<vector<int>> visited(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));
    
    queue<pair<int, int>> q;
    visited[1][1] = 1;
    dist[1][1] = 1;
    q.push(make_pair(1, 1));

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i != 4; i++) {
            int ny = y + dy[i];    //n = next
            int nx = x + dx[i]; 

            if (0 < nx && nx <= n && 0 < ny && ny <= m) {
                if (maps[ny - 1][nx - 1] && !visited[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + 1;
                    if (ny == m && nx == n) {
                        return dist[ny][nx];
                    }
                    visited[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return -1;
}