#include <iostream>
using namespace std;

int main()
{
	int t = 5;
	int num = 0, sum = 0;
	while (t--) 
	{ 
		cin >> num; 
		sum += num; 
	}
	cout << sum;
	return 0;
}