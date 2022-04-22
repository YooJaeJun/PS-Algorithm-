#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> nodes;
vector<int> visited;
int ans = 1e9;

void bt(int depth, vector<int>& team1, int idx) {
	if (depth == n / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i != n; i++) {
			for (int j = i + 1; j != n; j++) {
				auto itI = find(team1.begin(), team1.end(), i);
				auto itJ = find(team1.begin(), team1.end(), j);
				if (itI != team1.end() && itJ != team1.end()) {
					sum1 += nodes[i][j] + nodes[j][i];
				}
				else if (itI == team1.end() && itJ == team1.end()) {
					sum2 += nodes[i][j] + nodes[j][i];
				}
			}
		}

		ans = min(ans, abs(sum1 - sum2));
		
		return;
	}

	for (int i = idx; i != n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		team1.push_back(i);
		bt(depth + 1, team1, i + 1);
		team1.pop_back();
		visited[i] = false;
	}
}

void solution() {
	cin >> n;
	nodes.resize(n);
	visited.resize(n);
	for (int i = 0; i != n; i++) {
		nodes[i].resize(n);
	}
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			cin >> nodes[i][j];
		}
	}

	vector<int> team;
	bt(0, team, 0);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}