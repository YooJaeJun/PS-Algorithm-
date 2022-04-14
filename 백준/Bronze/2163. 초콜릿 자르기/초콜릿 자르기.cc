#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n, m;
	cin >> n >> m;
	cout << n * m - 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}