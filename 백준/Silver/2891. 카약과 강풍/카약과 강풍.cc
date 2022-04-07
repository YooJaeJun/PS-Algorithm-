#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n, s, r;
	cin >> n >> s >> r;
	vector<int> cayak(n + 1);
	for (int i = 0; i != s; i++) {
		int idx;
		cin >> idx;
		cayak[idx] = -1;
	}
	for (int i = 0; i != r; i++) {
		int idx;
		cin >> idx;
		cayak[idx]++;
	}
	
	for (int i = 1; i != cayak.size(); i++) {
		if (cayak[i] == 1 && cayak[i - 1] == -1) {
			cayak[i] = 0;
			cayak[i - 1] = 0;
		}
		if (cayak[i] == 1 && i + 1 < cayak.size() && cayak[i + 1] == -1) {
			cayak[i] = 0;
			cayak[i + 1] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i != cayak.size(); i++) {
		if (cayak[i] == -1) {
			ans++;
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}