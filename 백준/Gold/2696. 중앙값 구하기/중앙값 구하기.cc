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


void solution()
{
	int n;
	cin >> n;
	priority_queue<int> maxheap;
	priority_queue<int, vi, greater<int>> minheap;

	int midCnt = n % 2 == 0 ? n / 2 : n / 2 + 1;
	cout << midCnt << '\n';

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		minheap.push(num);

		if (minheap.size() > maxheap.size())
		{
			maxheap.push(minheap.top());
			minheap.pop();
		}

		if (minheap.empty() == false && maxheap.empty() == false)
		{
			if (minheap.top() < maxheap.top())
			{
				int minn = minheap.top();
				int maxn = maxheap.top();
				minheap.pop();
				maxheap.pop();
				maxheap.push(minn);
				minheap.push(maxn);
			}
		}

		if (i % 2 == 0)
		{
			cout << maxheap.top() << ' ';
		}
	}

	cout << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}