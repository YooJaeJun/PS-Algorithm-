#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;

int n, m;
vi arr, visited;

void bt(vi& v)
{
	if (v.size() == m)
	{
		for (auto& elem : v)
			cout << elem << ' ';
		cout << '\n';
		
		return;
	}

	int before = -1;
	for (int i = 0; i < n; i++)
	{
		if (visited[i]) 
			continue;
		if (before == -1) 
			before = arr[i];
		else if (before == arr[i])
			continue;
		before = arr[i];

		visited[i] = true;
		v.push_back(arr[i]);
		bt(v);
		v.pop_back();
		visited[i] = false;
	}
}

void solution()
{
	cin >> n >> m;
	arr.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	vi v;
	bt(v);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}