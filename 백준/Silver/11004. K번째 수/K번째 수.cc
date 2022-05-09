#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	int n, k;
	cin >> n >> k;
	vi arr(n);
	for (int i = 0; i != n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << arr[k - 1];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}