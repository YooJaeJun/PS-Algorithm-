#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> nodes;

void bt(vector<int>& v, int idx) {
	if (v.size() == m) {
		for (auto& elem : v) {
			cout << elem << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i != n; i++) {
		v.push_back(nodes[i]);
		bt(v, i);
		v.pop_back();
	}
}

void solution() {
	cin >> n >> m;
	nodes = vector<int>(n);
	for (int i = 0; i != n; i++) {
		cin >> nodes[i];
	}
	sort(nodes.begin(), nodes.end());
	vector<int> v;
	bt(v, 0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}