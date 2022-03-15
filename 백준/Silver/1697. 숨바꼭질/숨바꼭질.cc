#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[3] = { 1,-1,2 };
int nodes[100001] = { 0, };
int n, k;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (q.empty() == false) {
		int x = q.front();
		q.pop();
		if (x == k) { return; }
		// *2부터 체크하면 nodes[0] = 1이 되어버림
		for (auto& next : { x + dx[0], x + dx[1], x * dx[2] }) {
			if (next < 0 || next > 100001) { continue; }
			if (nodes[next] != 0) { continue; }// 이미 방문
			nodes[next] = nodes[x] + 1;
			q.push(next);
		}
	}
}

void solution() {
	cin >> n >> k;
	bfs(n);
	cout << nodes[k];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}