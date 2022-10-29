#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	int n;
	cin >> n;
	vi road(n - 1);
	for (int i = 0; i != n - 1; i++) {
		cin >> road[i];
	}
	vi price(n);
	for (int i = 0; i != n; i++) {
		cin >> price[i];
	}

	int standard = price[0];
	int sum = 0;

	for (int i = 1; i != n; i++) {
		sum += standard * road[i - 1];
		if (standard > price[i]) {
			standard = price[i];
		}
	}
	cout << sum;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}