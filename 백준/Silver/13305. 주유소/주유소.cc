#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);	// 비용, 거리
	for (int i = 0; i != n - 1; i++) {
		cin >> v[i].second;
	}
	for (int i = 0; i != n; i++) {
		cin >> v[i].first;
	}

	int minIdx = min_element(v.begin(), v.end() - 1) - v.begin();
	
	int sum = 0;
	for (int i = 0; i != n; i++) {
		if (i < minIdx) {
			sum += v[i].first * v[i].second;
		}
		else {
			int remainDist = 0;
			for (int j = i; j != n; j++) {
				remainDist += v[j].second;
			}
			sum += v[i].first * remainDist;
			break;
		}
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}