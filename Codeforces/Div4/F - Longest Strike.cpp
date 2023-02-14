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
	map<int, int> dic;
	for (int i = 0; i != n; i++) {
		int num;
		cin >> num;
		dic[num]++;
	}

	vi v;
	for (auto& elem : dic) {
		if (elem.second >= k) {
			v.push_back(elem.first);
		}
	}

	if (v.empty()) {
		cout << -1 << '\n';
		return;
	}
	
	int l = v[0], r = v[0];
	int beforeL = v[0], mx = 0;

	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] + 1 == v[i]) {
			if (v[i] - beforeL > mx) {
				l = beforeL;
				r = v[i];
				mx = v[i] - beforeL;
			}
		}
		else {
			beforeL = v[i];
		}
	}

	cout << l << ' ' << r << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}