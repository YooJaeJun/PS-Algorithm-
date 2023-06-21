#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) { return p1.first < p2.first; }
	else { return p1.second < p2.second; }
}

void solution() {
	int n;
	cin >> n;
	vector<pair<int, int>> nodes(n);
	for (int i = 0; i != n; i++) {
		cin >> nodes[i].first >> nodes[i].second;
	}

	sort(nodes.begin(), nodes.end(), comp);

	int endTime = 0, cnt = 0;
	for (int i = 0; i != n; i++) {
		if (endTime <= nodes[i].first) {
			endTime = nodes[i].second;
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}