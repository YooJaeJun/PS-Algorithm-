#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		deque<pair<int, int>> dq;
		for (int i = 0; i != n; i++) {
			int num;
			cin >> num;
			dq.push_back({ num,i });
		}
		deque<pair<int, int>> tmp(n);	// 비교용
		for (int i = 0; i != n; i++) {
			tmp[i] = dq[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (dq[i].first < dq[j].first) {
					dq.push_back(dq[i]);
					dq.erase(dq.begin() + i);
					i--;
					break;
				}
			}
		}
		for (int i = 0; i != n; i++) {
			if (dq[i] == tmp[m]) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}