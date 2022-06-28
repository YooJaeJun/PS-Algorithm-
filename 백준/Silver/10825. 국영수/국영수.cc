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

struct record
{
	string name;
	int korean, english, math;
};

void solution()
{
	int n;
	cin >> n;
	vector<record> student(n);
	forn(i, n)
	{
		cin >> student[i].name >> student[i].korean >> student[i].english >> student[i].math;
	}
	sort(student.begin(), student.end(), [&](record a, record b) {
		if (a.korean == b.korean)
		{
			if (a.english == b.english)
			{
				if (a.math == b.math)
				{
					return a.name < b.name;
				}
				return a.math > b.math;
			}
			return a.english < b.english;
		}
		return a.korean > b.korean;
		});
	for (auto& elem : student)
	{
		cout << elem.name << '\n';
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}