#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
bool possible;

void dfs(int start, int end) {
	visited[start] = true;
	for (int i = 0; i != nodes[start].size(); i++) {
		if (nodes[start][i] == 1) {	// 연결된 애들만 체크
			if (i == end) {
				possible = true;
				return;
			}
			if (visited[i] == false) {
				dfs(i, end);
			}
		}
	}
}

void solution() {
	int n;
	cin >> n;
	nodes.resize(n);
	visited.resize(n);
	for (int i = 0; i != n; i++) {
		nodes[i].resize(n);
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				nodes[i][j] = 1;	// 연결
			}
		}
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			possible = false;
			fill(visited.begin(), visited.end(), false);

			dfs(i, j);
			cout << possible << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}