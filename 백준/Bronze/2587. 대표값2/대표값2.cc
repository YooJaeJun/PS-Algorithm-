#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	vector<int> v(5);
	int sum = 0;
	for (int i = 0; i != 5; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int aver = sum / 5;
	sort(v.begin(), v.end());
	cout << aver << '\n' << v[2];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}