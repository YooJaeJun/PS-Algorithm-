#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;
#define gridCheck() if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;


void solution()
{
	const int n = 4;
	vi arr(n);
	forn(i, n) cin >> arr[i];
	if (arr[0] < arr[1] and arr[1] < arr[2] and arr[2] < arr[3]) cout << "Fish Rising";
	else if (arr[0] > arr[1] and arr[1] > arr[2] and arr[2] > arr[3]) cout << "Fish Diving";
	else if (arr[0] == arr[1] and arr[1] == arr[2] and arr[2] == arr[3]) cout << "Fish At Constant Depth";
	else cout << "No Fish";
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}