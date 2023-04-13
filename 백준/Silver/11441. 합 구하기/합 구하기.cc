#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> psum(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		psum[i] += psum[i - 1] + num;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", psum[e] - psum[s - 1]);
	}
}