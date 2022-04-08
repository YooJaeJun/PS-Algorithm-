#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes;
int k;
vector<bool> visited;

void bt(vector<int>& v, int start) {
	if (v.size() == 6) {
		for (auto& elem : v) {
			cout << elem << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i != k; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		v.push_back(nodes[i]);
		bt(v, i);
		v.pop_back();
		visited[i] = false;
	}
}

void solution() {
	while (1) {
		cin >> k;
		if (k == 0) return;
		nodes.resize(k);
		visited.resize(k);
		for (int i = 0; i != k; i++) {
			cin >> nodes[i];
		}
		vector<int> v;
		bt(v, 0);
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}