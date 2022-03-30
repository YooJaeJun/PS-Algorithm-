#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int k, n, m;
	cin >> k >> n >> m;
	int ans = k * n - m > 0 ? k * n - m : 0;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}