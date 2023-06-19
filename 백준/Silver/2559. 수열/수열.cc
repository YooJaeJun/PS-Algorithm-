#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> psum(n);
	cin >> psum[0];

	for (int i=1; i<n; i++)
	{
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}

	int ans = psum[k - 1];
	int s = 0, e = k;

	while (e < n)
	{
		ans = max(ans, psum[e] - psum[s]);
		s++;
		e++;
	}

	cout << ans;

	return 0;
}