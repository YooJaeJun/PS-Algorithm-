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


map<string, float> dic;

void setDB()
{
	dic["A+"] = 4.3;	dic["A0"] = 4.0;	dic["A-"] = 3.7;
	dic["B+"] = 3.3;	dic["B0"] = 3.0;	dic["B-"] = 2.7;
	dic["C+"] = 2.3;	dic["C0"] = 2.0;	dic["C-"] = 1.7;
	dic["D+"] = 1.3;	dic["D0"] = 1.0;	dic["D-"] = 0.7;
	dic["F"] = 0.0;
}

void solution()
{
	setDB();
	string s;
	cin >> s;
	printf("%.1f", dic[s]);
}

int32_t main()
{
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}