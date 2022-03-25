#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	for (int i = 0; i != 2; i++) {
		vector<int> v(10);
		for (int i = 0; i != 10; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << v[9] + v[8] + v[7] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}