#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> psum(n + 1);

	int input;
	cin >> input;
	psum[1] = input;

	for (int i = 2; i <= n; i++)
	{
		cin >> input;
		psum[i] = psum[i - 1] + input;
	}

	for (int i=0; i<m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		cout << psum[n2] - psum[n1 - 1] << '\n';
	}

	return 0;
}
