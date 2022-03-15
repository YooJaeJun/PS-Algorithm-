#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes;
vector<int> cnts;
vector<int> visited;
int n, cnt;

void dfs(int start) {
	visited[start] = 1;
	cnt++;
	for (auto& node : nodes[start]) {
		if (visited[node] == 0) {
			dfs(node);
		}
	}

}

int main() {
	int m;
	cin >> n >> m;
	nodes.resize(n + 1);
	cnts.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i != m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		nodes[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[j] = 0;
		}
		dfs(i);
		cnts[i] = cnt;
		cnt = 0;
	}

	int maxIdx = max_element(cnts.begin(), cnts.end()) - cnts.begin();
	int max = cnts[maxIdx];
	vector<int> maxIdxs;
	maxIdxs.push_back(maxIdx);
	for (int i = 1; i != cnts.size(); i++) {
		if (maxIdx != i && max < cnts[i]) {
			maxIdx = i;
			max = cnts[i];
			maxIdxs.clear();
			maxIdxs.push_back(i);
		}
		else if (maxIdx != i && max == cnts[i]) {
			maxIdxs.push_back(i);
		}
	}
	sort(maxIdxs.begin(), maxIdxs.end());
	for (auto& elem : maxIdxs) {
		printf("%d ", elem);
	}

	return 0;
}