#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int solution(int n, vector<vector<int>> wires) {
    vvi nodes(n + 1, vi(n + 1));

    for (auto& wire : wires)
    {
        nodes[wire[0]][wire[1]] = nodes[wire[1]][wire[0]] = 1;
    }

    vi visited;
    int ans = n + 1;

    for (auto& wire : wires)    // 하나씩 끊어보기
    {
        nodes[wire[0]][wire[1]] = 0;
        nodes[wire[1]][wire[0]] = 0;

        visited = vi(n + 1);

        // bfs
        vi cnts;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i]) continue;
            visited[i] = true;
            queue<int> q;
            q.push(i);
            int cnt = 0;

            while (q.empty() == false)
            {
                int cur = q.front();
                q.pop();
                cnt++;
                for (int i = 1; i < nodes[cur].size(); i++)
                {
                    if (nodes[cur][i] == 0) continue;
                    if (visited[i]) continue;
                    visited[i] = true;
                    q.push(i);
                }
            }
            cnts.push_back(cnt);
            cnt = 0;
        } // bfs 끝

        int minn, maxn;
        minn = maxn = cnts[0];
        for (auto& elem : cnts)
        {
            minn = min(minn, elem);
            maxn = max(maxn, elem);
        }
        ans = min(ans, maxn - minn);

        nodes[wire[0]][wire[1]] = 1;    // 잇기
        nodes[wire[1]][wire[0]] = 1;
    }

    return ans;
}

int main()
{
    solution(9, { {1, 3},{2, 3},{3, 4},{4, 5},{4, 6},{4, 7},{7, 8},{7, 9} });
    return 0;
}