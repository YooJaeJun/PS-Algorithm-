#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<pair<int, int>> ranks(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i].first >> v[i].second;
		ranks[i].first = v[i].first;
		ranks[i].second = 1;
	}

	int rank = 1;
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != i; j++) {
			if (v[i].first > v[j].first && 
				v[i].second > v[j].second) {
				ranks[j].second++;
			}
			else if (v[i].first < v[j].first && 
				v[i].second < v[j].second) {
				ranks[i].second++;
			}
		}
	}

	for (int i = 0; i != n; i++) {
		cout << ranks[i].second << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}