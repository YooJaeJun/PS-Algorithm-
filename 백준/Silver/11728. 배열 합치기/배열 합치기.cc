#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n, m;
	cin >> n >> m;
	vector<int> v1(n + m), v2(m);
	for (int i = 0; i != n; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i != m; i++) {
		cin >> v2[i];
	}

	for (int i = 0; i != m; i++) {
		v1[n + i] = v2[i];
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i != v1.size(); i++) {
		cout << v1[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}