#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> d;
vector<bool> visited;
int cnt = 0;

void dfs(int k, int depth) {
    for (int i = 0; i != d.size(); i++) {
        if (visited[i]) continue;
        if (k < d[i][0]) continue;
        visited[i] = true;
        dfs(k - d[i][1], depth + 1);
        visited[i] = false;
        cnt = max(cnt, depth);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    d = dungeons;
    visited.resize(d.size());
    dfs(k, 1);
    return cnt;
}

int main() {
    printf("%d", solution(80, { {80, 20}, {50, 40}, {30, 10} }));
    return 0;
}