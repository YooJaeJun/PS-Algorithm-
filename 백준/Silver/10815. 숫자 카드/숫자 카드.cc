#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i != m; i++) {
		int num;
		cin >> num;
		
		// 이분탐색
		int start = 0;
		int end = v.size() - 1;
		bool found = false;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (v[mid] == num) {
				cout << 1 << ' ';
				found = true;
				break;
			}
			else if (v[mid] < num) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		if (false == found) {
			if (start == num || end == num) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}