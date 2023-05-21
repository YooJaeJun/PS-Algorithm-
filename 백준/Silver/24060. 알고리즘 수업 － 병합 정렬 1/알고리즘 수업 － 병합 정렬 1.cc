#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a, tmp;
int depth = 0, answer = -1;

void Merge(int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r)
	{
		if (a[i] <= a[j])
			tmp[t++] = a[i++];
		else
			tmp[t++] = a[j++];
	}

	while (i <= q)
		tmp[t++] = a[i++];
	while (j <= r)
		tmp[t++] = a[j++];

	i = p;
	t = 1;
	while (i <= r)
	{
		a[i++] = tmp[t++];

		depth++;
		if (depth == k)
		{
			answer = a[i - 1];
			return;
		}
	}
}

void MergeSort(int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(p, q);

		if (depth == k)
			return;

		MergeSort(q + 1, r);

		if (depth == k)
			return;

		Merge(p, q, r);
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	a.resize(n + 1);
	tmp.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	MergeSort(1, n);

	cout << answer;

	return 0;
}