#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);	// y, x
	for (auto& elem : v) {
		cin >> elem.second >> elem.first;
	}
	stable_sort(v.begin(), v.end());
	for (auto& elem : v) {
		cout << elem.second << ' ' << elem.first << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}