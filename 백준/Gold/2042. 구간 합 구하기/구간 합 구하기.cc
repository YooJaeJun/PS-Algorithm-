#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 세그먼트 트리
vector<long long> tree;
vector<long long> inputs;

// 구간 합 트리 생성
long long init(int start, int end, int node) {
	if (start == end) { return tree[node] = inputs[start]; }
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
// 구간합 구하기
long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) { return 0; }	// 범위 밖
	if (left <= start && end <= right) { return tree[node]; }	// 범위 안
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
// 특정 원소값 수정
void update(int start, int end, int node, int index, long long dif) {
	if (index < start || index > end) { return; }	// 범위 밖
	// 범위 안==> 다른 원소도 갱신
	tree[node] += dif;
	if (start == end) { return; }
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

void solution() {
	int n, m, k;
	cin >> n >> m >> k;	
	tree.resize(n * 4);
	inputs.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
	}

	init(0, n - 1, 1);

	for (int i = 0; i != m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, n - 1, 1, b - 1, c - inputs[b - 1]);
			inputs[b - 1] = c;
		}
		else {
			cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}