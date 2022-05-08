#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	int s;
	cin >> s;
	int sum = 0;
	int n = 0;
	for (int i = 1; i <= s; i++) {
		sum += i;
		if (sum > s) {
			break;
		}
		else if (sum < s) {
			++n;
		}
		else {
			++n;
			break;
		}
	}
	cout << n;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}