#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;

vvb visited;
int cnt = 0;

int brute(int start, int end, int n)
{
	if (visited[start][end]) return 0;
	visited[start][end] = true;
	if (start >= end) return 0;
	if (start <= n && n <= end)
	{
		cnt++;
		return brute(start + 1, end, n) + brute(start, end - 1, n) + brute(start + 1, end - 1, n);
	}
	return 0;
}

void solution()
{
	int s;
	cin >> s;
	vi arr(s);
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	int n;
	cin >> n;

	sort(arr.begin(), arr.end());
	visited = vvb(arr.back(), vb(arr.back()));

	int idx = lower_bound(arr.begin(), arr.end(), n) - arr.begin();
	if (idx == 0)
	{
		brute(1, arr[idx] - 1, n);
	}
	else
	{
		brute(arr[idx - 1] + 1, arr[idx] - 1, n);
	}
	
	cout << cnt;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}