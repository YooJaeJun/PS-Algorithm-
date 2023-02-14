#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

void solution() {
	int x, y;
	cin >> x >> y;
	if (y % x != 0) {
		cout << 0 << ' ' << 0 << '\n';
		return;
	}
	y /= x;
	cout << 1 << ' ' << y << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}