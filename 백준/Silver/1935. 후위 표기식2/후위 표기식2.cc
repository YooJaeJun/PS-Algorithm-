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
	string s;
	cin >> s;
	map<int, double> dic;
	for (int i = 0; i != n; i++) {
		int num;
		cin >> num;
		dic[i] = num;
	}

	double ans = 0;
	stack<double> st;
	for (int i = 0; i != s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			st.push(dic[(int)s[i] - 'A']);
		}
		else {
			double n2 = st.top();
			st.pop();
			double n1 = st.top();
			st.pop();
			if (s[i] == '+') {
				st.push(n1 + n2);
			}
			else if (s[i] == '-') {
				st.push(n1 - n2);
			}
			else if (s[i] == '*') {
				st.push(n1 * n2);
			}
			else {
				st.push(n1 / n2);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}