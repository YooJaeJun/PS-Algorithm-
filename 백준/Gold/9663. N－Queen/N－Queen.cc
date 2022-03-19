#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;
const int maxN = 15;
int queen[maxN];

bool isValid(int row) {
	for (int i = 0; i < row; i++) {
		if (queen[i] == queen[row] || 
			row - i == abs(queen[row] - queen[i])) {
			return false;
		}
	}
	return true;
}

void nqueen(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int col = 0; col < n; col++) {
		queen[row] = col;
		// 현재 퀸 위치가 이전의 모든 퀸의 같은 행, 혹은 열, 혹은 대각선에 있는지.
		if (isValid(row)) {
			nqueen(row + 1);
		}
	}
}

void solution() {
	cin >> n;
	nqueen(0);
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}