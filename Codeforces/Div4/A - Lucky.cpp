#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	string s;
	cin >> s;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i != 3; i++) {
		sum1 += s[i];
	}
	for (int i = 3; i != 6; i++) {
		sum2 += s[i];
	}
	if (sum1 == sum2) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}