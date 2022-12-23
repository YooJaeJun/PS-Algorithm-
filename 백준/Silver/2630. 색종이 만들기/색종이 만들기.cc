#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int zeroNum;
int oneNum;
vector<vector<int>> nodes;

void div(int x, int y, int size) {
	if (size < 1) {
		return;
	}
	int num = nodes[x][y];
	bool isSame = true;
	for (int i = x; i != x + size; i++) {
		for (int j = y; j != y + size; j++) {
			if (num != nodes[i][j]) {
				isSame = false;
			}
		}
	}
	if (isSame) {
		if (num == 0) { zeroNum++; }
		else { oneNum++; }
	}
	else {
		// 1,2,3,4사분면
		div(x, y, size / 2);
		div(x + size / 2, y, size / 2);
		div(x, y + size / 2, size / 2);
		div(x + size / 2, y + size / 2, size / 2);
	}
}

void solution() {
	cin >> n;
	nodes.resize(n);
	for (auto& node : nodes) {
		node.resize(n);
	}
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			cin >> nodes[i][j];
		}
	}
	div(0, 0, n);

	cout << zeroNum << '\n' << oneNum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}