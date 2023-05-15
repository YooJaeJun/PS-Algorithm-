#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void bt(int depth) {
	if (depth == m) {
		for (auto& elem : v) {
			cout << elem << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		v[depth] = i;
		if (depth > 0 && v[depth - 1] > v[depth]) { continue; }
		bt(depth + 1);
	}
}

void solution() {
	cin >> n >> m;
	v.resize(m);
	bt(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}