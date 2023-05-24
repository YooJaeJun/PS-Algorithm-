#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int FindParent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = FindParent(parent[a]);
}

void Union(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool IsUnion(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	return a == b;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	bool q = false;
	int a = 0, b = 0;
	string answer[2]{ "NO", "YES" };

	while (m--)
	{
		cin >> q >> a >> b;

		if (q)
			cout << answer[IsUnion(a, b)] << '\n';
		else
			Union(a, b);
	}


	return 0;
}