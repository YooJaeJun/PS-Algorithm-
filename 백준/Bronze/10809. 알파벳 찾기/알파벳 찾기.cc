#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> alpha(26, -1);
	string s;
	cin >> s;

	for (int i=0; i<s.size(); i++)
		if (alpha[s[i] - 'a'] == -1)
			alpha[s[i] - 'a'] = i;

	for (auto& elem : alpha)
		cout << elem << ' ';

	return 0;
}