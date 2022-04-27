#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;

int getParent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = getParent(parent[n]);
}

void unionParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);
	if (n1 < n2) parent[n2] = n1;
	else parent[n1] = n2;
}

bool findParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);
	return n1 == n2;
}

struct edge {
	int n1, n2, c;
	bool operator<(edge ed) {
		return c < ed.c;
	}
};

void solution() {
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		vector<edge> nodes;
		for (int i = 0; i != m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			nodes.push_back({ a,b,c });
		}

		sort(nodes.begin(), nodes.end());

		parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}

		int sum = 0, total = 0;
		for (int i = 0; i != nodes.size(); i++) {
			total += nodes[i].c;
			if (false == findParent(nodes[i].n1, nodes[i].n2)) {
				sum += nodes[i].c;
				unionParent(nodes[i].n1, nodes[i].n2);
			}
		}

		cout << total - sum << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}