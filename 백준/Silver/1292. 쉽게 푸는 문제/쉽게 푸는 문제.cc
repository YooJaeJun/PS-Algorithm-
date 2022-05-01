#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

void solution() {
	int a, b;
	cin >> a >> b;
	a--;	b--;
	int sum = 0, idx = 0;
	for (int i = 1; i != 1000; i++) {
		for (int j = 0; j != i; j++) {
			if (idx >= a) {
				sum += i;
			}
			if (idx == b) {
				cout << sum;
				return;
			}
			idx++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}