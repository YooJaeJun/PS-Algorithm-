#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nodes(n);
	for (int i = 0; i != n; i++) {
		cin >> nodes[i];
	}
	sort(nodes.begin(), nodes.end());

	vector<int> v;
	int max1 = 0;
	for (int i = nodes.size() - 1; i >= 0; i--) {
		v.emplace_back(nodes[i]);
		max1 = max(max1, v.back() * (int)v.size());
	}
	cout << max1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}