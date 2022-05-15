#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution()
{
	string s;
	cin >> s;
	int b;
	cin >> b;

	int coef = b, sum = 0;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		int digit;
		if (s[i] >= 'A') digit = (int)s[i] - 'A' + 10;
		else digit = (int)s[i] - '0';

		if (i == s.size() - 1) sum += digit;
		else
		{
			sum += digit * coef;
			coef *= b;
		}
	}
	cout << sum;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}