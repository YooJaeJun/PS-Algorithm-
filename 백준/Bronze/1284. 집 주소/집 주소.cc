#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solution() {
	while (1)
	{
		string s;
		cin >> s;
		if (s == "0") return;

		int sum = s.size() - 1 + 2;
		for (auto& ch : s)
		{
			if (ch == '1') sum += 2;
			else if (ch == '0') sum += 4;
			else sum += 3;
		}
		cout << sum << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}