#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i=0; i<n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<int> psum(n);
	psum[0] = v[0];

	for (int i=1; i<n; i++)
		psum[i] += psum[i - 1] + v[i];

	int ans = 0;

	for (int i=0; i<n; i++)
		ans += psum[i];

	cout << ans;

	return 0;
}