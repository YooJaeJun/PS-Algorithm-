#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}
	vector<int> kill(n);
	int ans = 0;
	for (int i = 0; i != n - 1; i++) {
		for (int j = i + 1; j != n; j++) {
			if (v[i] < v[j]) {
				break;
			}
			kill[i]++;
		}
		if (ans < kill[i]) {
			ans = kill[i];
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}