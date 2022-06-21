#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

int parent[1001] = { 0, };

int getParent(const int a)
{
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

struct node
{
	int n1, n2;
	double dist;
	bool operator<(const node& other) const
	{
		return dist < other.dist;
	}
};

double getDistance(const double x1, const double y1, const double x2, const double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solution()
{
	int n, m;
	cin >> n >> m;
	vector<pii> god(n + 1);
	forn1(i, n)
	{
		int x, y;
		cin >> x >> y;
		god[i] = { x, y };
	}

	forn1(i, n) parent[i] = i;

	forn(i, m)
	{
		int n1, n2;
		cin >> n1 >> n2;
		unionParent(n1, n2);
	}

	vector<node> nodes;
	forn1(i, n)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double dist = getDistance(god[i].first, god[i].second, god[j].first, god[j].second);
			nodes.push_back({ i, j, dist });
		}
	}

	sort(nodes.begin(), nodes.end());

	double sum = 0.0f;
	forn(i, nodes.size())
	{
		if (false == findParent(nodes[i].n1, nodes[i].n2))
		{
			sum += nodes[i].dist;
			unionParent(nodes[i].n1, nodes[i].n2);
		}
	}

	printf("%.2lf", sum);
}

int32_t main()
{
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}