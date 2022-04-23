#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solution() {
	int v, e;
	cin >> v >> e;
	cout << 2 - v + e << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}