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
	int n, m;
	cin >> n >> m;

	vector<edge> nodes;
	for (int i = 0; i != m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes.push_back({ a, b, c });
	}

	sort(nodes.begin(), nodes.end());

	parent = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	int maxC = 0;
	for (int i = 0; i != nodes.size(); i++) {
		if (false == findParent(nodes[i].n1, nodes[i].n2)) {
			sum += nodes[i].c;
			maxC = max(maxC, nodes[i].c);
			unionParent(nodes[i].n1, nodes[i].n2);
		}
	}

	cout << sum - maxC;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}