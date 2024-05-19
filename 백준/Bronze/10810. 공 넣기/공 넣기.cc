#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> basket(n);
	for (int t=0; t<m; t++)
	{
		int i, j, k;
		cin >> i >> j >> k;
		for (int index=i-1; index<j; index++)
		{
			basket[index] = k;
		}
	}
	for (auto& elem : basket)
	{
		cout << elem << ' ';
	}
}
