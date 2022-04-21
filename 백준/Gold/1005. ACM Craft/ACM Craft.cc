#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

void topoSort(int n, int k, vector<int>& time, vector<vector<int>>& nodes, vector<int>& deg, int end) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> resultTime(n + 1);

	while (q.empty() == false) {
		int cur = q.front();
		q.pop();
		resultTime[cur] = max(resultTime[cur], time[cur]);

		for (auto next : nodes[cur]) {
			resultTime[next] = max(resultTime[next], resultTime[cur] + time[next]);
			if (--deg[next] == 0) {
				q.push(next);
			}
		}
	}
	cout << resultTime[end] << '\n';
}

void solution() {
	long long n, k;
	cin >> n >> k;
	vector<int> time(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
	}
	vector<vector<int>> nodes(n + 1);
	vector<int> deg(n + 1);
	for (int i = 1; i <= k; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		deg[n2]++;
	}
	int end;
	cin >> end;

	topoSort(n, k, time, nodes, deg, end);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}