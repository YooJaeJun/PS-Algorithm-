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
	edge(int an1, int an2, int ac) :
		n1(an1), n2(an2), c(ac) {}
	bool operator <(edge ed) {
		return c < ed.c;
	}
};

void solution() {
	int v, e;
	cin >> v >> e;
	parent = vector<int>(v + 1);
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	vector<edge> nodes;
	for (int i = 0; i != e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes.push_back(edge(a, b, c));
	}

	sort(nodes.begin(), nodes.end());

	int sum = 0;
	for (int i = 0; i != nodes.size(); i++) {
		if (false == findParent(nodes[i].n1, nodes[i].n2)) {
			sum += nodes[i].c;
			unionParent(nodes[i].n1, nodes[i].n2);
		}
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}