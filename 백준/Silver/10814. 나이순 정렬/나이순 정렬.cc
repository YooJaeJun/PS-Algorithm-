#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	struct Info
	{
		int index;
		int age;
		string name;

		bool operator<(const Info& other) const
		{
			if (age == other.age)
				return index < other.index;
			return age < other.age;
		}
	};

	vector<Info> v(n);

	for (int i=0; i<n; i++)
	{
		cin >> v[i].age >> v[i].name;
		v[i].index = i;
	}

	sort(v.begin(), v.end());

	for (auto& elem : v)
		cout << elem.age << ' ' << elem.name << '\n';

	return 0;
}