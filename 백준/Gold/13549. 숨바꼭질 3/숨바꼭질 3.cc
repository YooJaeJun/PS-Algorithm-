#include <bits/stdc++.h>
using namespace std;

int n, k;
const int inf = 1e9;
int t[200001];

void bfs() {
	fill(t, t + 200001, inf);
	deque<int> dq;
	t[n] = 0;
	dq.push_front(n);

	while (false == dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		if (cur == k) {
			return;
		}

		for (auto& elem : { cur * 2, cur - 1, cur + 1  }) {
			for (int next = elem; next >= 0 && next <= 200000; next *= 2) {
				if (next == cur * 2) {
					if (t[next] > t[cur]) {
						t[next] = t[cur];
						dq.push_front(next);
					}
				}
				else {
					if (t[next] > t[cur] + 1) {
						t[next] = t[cur] + 1;
						dq.push_back(next);
					}
				}
				if (next == 0) break;
			}
		}
	}
}

void solution() {
	cin >> n >> k;
	bfs();
	cout << t[k];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}