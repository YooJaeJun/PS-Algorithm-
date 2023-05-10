#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> dic1;
	unordered_map<int, string> dic2;
	string input;
	
	for (int i=1; i<=n; i++)
	{
		cin >> input;
		dic1[input] = i;
		dic2[i] = input;
	}

	while (m--)
	{
		cin >> input;
		if (input[0] >= 'A' && input[0] <= 'Z')
			cout << dic1[input] << '\n';
		else
		{
			int n = stoi(input);
			cout << dic2[n] << '\n';
		}
	}

	return 0;
}
