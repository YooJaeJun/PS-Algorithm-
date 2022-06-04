#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	priority_queue<int, vi, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	int result = 0;
	while (pq.size() > 1)
	{
		int sum = 0;
		sum += pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		result += sum;
	}
	cout << result << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}