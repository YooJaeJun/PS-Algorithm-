#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	switch (n1+n2+n3)
	{
	case 180:
		if (n1 == 60 && n2 == 60 && n3 == 60) {
			cout << "Equilateral";
		}
		else if (n1 == n2 || n2 == n3 || n1 == n3) {
			cout << "Isosceles";
		}
		else {
			cout << "Scalene";
		}
		break;
	default:
		cout << "Error";
		break;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}