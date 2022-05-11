#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool check(vector<string>& grid, int x, int y)
{
    int cnt = 0;
    for (int i = 0; i != 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (grid[nx][ny] == 'P') {
            if (grid[x][y] == 'P') {
                return false;
            }
            else {
                cnt++;
            }
        }
    }
    return cnt < 2;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto& place : places)
    {
        bool flag = true;
        grid = place;
        for (int x = 0; x != 5 && flag; ++x)
            for (int y = 0; y != 5 && flag; ++y)
                if (grid[x][y] == 'O' || grid[x][y] == 'P')
                    if (check(grid, x, y) == false)
                        flag = false;

        if (flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}