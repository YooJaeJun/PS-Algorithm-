#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<int> nodes;
vector<bool> visited;
const int inf = 1e9;
int ans = inf;

void bfs(int start, int end, int depth) {
	queue<pair<int, int>> q;
	q.push({ start, depth });
	visited[start] = true;

	while (q.empty() == false) {

		int nStart = q.front().first;
		int nDepth = q.front().second;
		q.pop();

		if (abs(end - nStart) % nodes[nStart] == 0) {
			ans = min(ans, nDepth);
			return;
		}

		for (int i = 1;; i++) {
			if (nStart + nodes[nStart] * i > n) break;
			q.push({ nStart + nodes[nStart] * i, nDepth + 1 });
		}
		for (int i = -1;; i--) {
			if (nStart + nodes[nStart] * i <= 0) break;
			q.push({ nStart + nodes[nStart] * i, nDepth + 1 });
		}
	}
}

void solution() {
	cin >> n;
	nodes.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
	}
	int start, end;
	cin >> start >> end;

	if (start == end) {
		cout << 0;
		return;
	}

	bfs(start, end, 1);
	if (ans == inf) cout << -1;
	else cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}