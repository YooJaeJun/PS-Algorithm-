#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> nodes;
vector<int> visited;
int ans = 1e9;

void bt(int depth, vector<bool>& team1, int idx) {
	if (depth == n / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i != n; i++) {
			for (int j = i + 1; j != n; j++) {
				if (team1[i] && team1[j]) {
					sum1 += nodes[i][j] + nodes[j][i];
				}
				else if (team1[i] == false && team1[j] == false) {
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
		team1[i] = true;
		bt(depth + 1, team1, i + 1);
		team1[i] = false;
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

	vector<bool> team(n);
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