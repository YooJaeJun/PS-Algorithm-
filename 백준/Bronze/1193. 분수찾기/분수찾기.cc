#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> ab = { 1, 1 };
	int iter = 1, idx = 0, cnt = 1;
	while(1) {
		if (cnt == n) { break; }

		idx = idx == 1 ? 0 : 1;
		ab[idx]++;
		cnt++;
		if (cnt == n) { break; }

		iter++;
		for (int j = 1; j < iter; j++) {
			ab[idx]--;
			idx = idx == 1 ? 0 : 1;
			ab[idx]++;
			cnt++;
			if (cnt == n) { break; }
			idx = idx == 1 ? 0 : 1;
		}
	}
	cout << ab[0] << '/' << ab[1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}