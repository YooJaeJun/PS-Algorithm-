#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, p;
	cin >> a >> p;

	unordered_map<int, bool> dic;
	vector<int> v;

	while (!dic[a])
	{
		dic[a] = true;
		v.emplace_back(a);
		int temp = a;
		int sum = 0;

		while (temp)
		{
			int temp2 = temp % 10;
			sum += pow(temp2, p);
			temp /= 10;
		}

		a = sum;
	}

	int idx = find(v.begin(), v.end(), a) - v.begin();
	cout << idx;

	return 0;
}