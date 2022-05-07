#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int>

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<pii>> nodes(N + 1, vector<pii>(N + 1));   // 거리, 노드

    for (int i = 0; i < road.size(); i++) {
        nodes[road[i][0]].push_back({ road[i][2], road[i][1] });
        nodes[road[i][1]].push_back({ road[i][2], road[i][0] });
    }

    // dijk
    vector<int> dist(N + 1, 1e9);
    vector<bool> ans(N + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리, 노드
    pq.push({ 0, 1 });
    dist[1] = 0;

    while (pq.empty() == false) {
        int cur = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (dist[cur] < distance) continue;

        for (auto& elem : nodes[cur]) {
            int next = elem.second;
            int nDistance = elem.first + distance;
            if (dist[next] > nDistance) {
                dist[next] = nDistance;
                pq.push({ nDistance, next });
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] <= K) {
            cnt++;
        }
    }
    return cnt;
}

#include <iostream>
int main() {
    cout << solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
    return 0;
}