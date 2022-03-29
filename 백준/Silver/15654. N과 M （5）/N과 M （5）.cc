#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> ans;
vector<int> nodes;

void bt(int depth) {
	if (depth == m) {
		for (auto& elem : ans) {
			cout << elem << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i != nodes.size(); i++) {
		auto it = find(ans.begin(), ans.end(), nodes[i]);
		if (it == ans.end()) {
			ans[depth] = nodes[i];
			bt(depth + 1);
			ans[depth] = 0;
		}
	}
}

void solution() {
	cin >> n >> m;
	ans.resize(m);
	nodes.resize(n);

	for (int i = 0; i != n; i++) {
		cin >> nodes[i];
	}
	sort(nodes.begin(), nodes.end());

	bt(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}