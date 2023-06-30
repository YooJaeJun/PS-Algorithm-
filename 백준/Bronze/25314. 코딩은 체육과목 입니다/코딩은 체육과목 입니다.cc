#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int size = n / 4;
	for (int i=0; i<size; i++)
		cout << "long ";
	cout << "int";

	return 0;
}