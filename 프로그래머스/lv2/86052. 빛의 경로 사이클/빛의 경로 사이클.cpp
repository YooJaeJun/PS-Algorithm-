#include <bits/stdc++.h>
using namespace std;

enum edir
{
    right, down, left, up
};
int dx[4] = { 0,1,0,-1 }; // 우하좌상
int dy[4] = { 1,0,-1,0 };
int visited[500][500][4];
vector<int> ans;
int n, m;

void search(vector<string>& grid, int sx, int sy, int x, int y, int dir, int depth)
{
    if (visited[x][y][dir])
    {
        ans.push_back(depth);
        return;
    }

    visited[x][y][dir] = true;
    int ndir = dir;
    if (grid[x][y] == 'L') ndir = (dir + 3) % 4;
    else if (grid[x][y] == 'R') ndir = (dir + 1) % 4;

    int nx = x + dx[ndir];
    int ny = y + dy[ndir];
    if (nx < 0) nx = n - 1;
    else if (nx >= n) nx = 0;
    if (ny < 0) ny = m - 1;
    else if (ny >= m) ny = 0;

    search(grid, sx, sy, nx, ny, ndir, depth + 1);
}

vector<int> solution(vector<string> grid) {
    n = grid.size();
    m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                if (visited[i][j][dir]) continue;
                search(grid, i, j, i, j, dir, 0);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}