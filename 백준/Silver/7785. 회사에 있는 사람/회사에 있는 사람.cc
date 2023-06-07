#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	map<string, bool> dic;
	string input, command;

	while (n--)
	{
		cin >> input >> command;
		dic[input] = (command == "enter") ? true : false;
	}

	for (auto it = --dic.end(); ; it--)
	{
		if (it->second != 0)
			cout << it->first << '\n';

		if (it == dic.begin())
			break;
	}

	return 0;
}