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
	priority_queue<int> maxHeap;
	priority_queue<int, vi, greater<int>> minHeap;

	int n1, n2;
	cin >> n1;
	cout << n1 << '\n';
	if (n == 1) return;

	cin >> n2;
	if (n1 >= n2)
	{
		maxHeap.push(n2); 
		minHeap.push(n1);
		cout << n2 << '\n';
	}
	else
	{
		maxHeap.push(n1); 
		minHeap.push(n2);
		cout << n1 << '\n';
	}

	for (int i = 2; i < n; i++)
	{
		int num;
		cin >> num;

		if (minHeap.top() < num)
			minHeap.push(num);
		else 
			maxHeap.push(num);

		if (maxHeap.size() >= minHeap.size() + 2)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (maxHeap.size() + 2 <= minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		int res = 0;
		if (maxHeap.size() == minHeap.size())
			res = maxHeap.top();
		else if (maxHeap.size() < minHeap.size())
			res = minHeap.top();
		else
			res = maxHeap.top();

		cout << res << '\n';
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