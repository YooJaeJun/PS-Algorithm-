#include <iostream>
#include <vector>
using namespace std;

int n, m;
int v[9] = { 0, };
bool check[9];

void backTracking(int depth) {
	if (depth == m) {
		for (int i = 1; i != m; i++) {
			if (v[i - 1] >= v[i]) {
				return;
			}
		}

		for (int i = 0; i != m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			v[depth] = i;
			backTracking(depth + 1);
			check[i] = false;
		}
	}
}

void solution() {
	cin >> n >> m;
	backTracking(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}