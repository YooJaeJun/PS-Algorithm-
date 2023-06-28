#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		unordered_map<string, int> dic;
		vector<string> voices;
		string input, prev;

		while (cin >> input)
		{
			if (input == "goes")
			{
				dic[prev] = 0;

				cin >> input;
				dic[input] = 0;

				break;
			}

			voices.emplace_back(input);
			dic[input]++;
			prev = input;
		}

		while (cin >> input)
		{
			if (input == "what")
			{
				for (int i = 0; i < 4; i++)
					cin >> input;
				break;
			}

			dic[input] = 0;
		}

		for (auto& elem : voices)
			if (dic[elem])
				cout << elem << ' ';
		cout << '\n';
	}

	return 0;
}