#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nodes;	// 노드--연결노드
vector<int> parents;	// 노드-부모

void bfs() {
	queue<int> q;
	q.push(1);
	while (false == q.empty()) {
		int x = q.front();
		q.pop();
		for (auto& elem : nodes[x]) {
			if (parents[elem] == 0) {
				parents[elem] = x;
				q.push(elem);
			}
		}
	}
}

void solution() {
	int n;
	cin >> n;
	nodes.resize(n + 1);
	parents.resize(n + 1);
	for (int i = 0; i != n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}
	bfs();
	for (int i = 2; i <= n; i++) {
		cout << parents[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}