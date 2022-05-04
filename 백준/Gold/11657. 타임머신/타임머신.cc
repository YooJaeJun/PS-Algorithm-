#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct edge {
	int start, end, weight;
};

int n, m;
vector<edge> nodes;
vi dist;

void bellman() {
	for (int i = 0; i != n - 1; i++) {
		for (auto& node : nodes) {
			if (dist[node.start] == INT_MAX) continue;
			dist[node.end] = min(dist[node.end], dist[node.start] + node.weight);
		}
	}
	for (auto& node : nodes) {
		if (dist[node.start] == INT_MAX) continue;
		if (dist[node.start] + node.weight < dist[node.end]) {
			cout << -1;
			return;
		}
	}
	for (int i = 2; i != dist.size(); i++) {
		if(dist[i] == INT_MAX) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}

void solution() {
	cin >> n >> m;
	for (int i = 0; i != m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		nodes.push_back({ s, e, w });
	}

	dist = vi(n + 1, INT_MAX);
	dist[1] = 0;

	bellman();
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}