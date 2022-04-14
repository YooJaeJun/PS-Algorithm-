#include <iostream>
#include <vector>
using namespace std;

const int n = 9;
int grid[n][n];
bool rows[n][n];
bool cols[n][n];
bool grid3x3[n][n];
bool isPrint = false;

void print() {
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
}

void bt(int depth) {
	if (isPrint) {
		return;
	}
	if (depth == 81) {
		print();
		isPrint = true;
		return;
	}
	
	int x = depth / n;	// 행
	int y = depth % n;	// 열

	if (grid[x][y] == 0) {
		for (int num = 1; num <= 9; num++) {	// 가능한 숫자들
			if (rows[x][num] || cols[y][num] || grid3x3[x / 3 * 3 + y / 3][num]) continue;

			rows[x][num] = true;
			cols[y][num] = true;
			grid3x3[x / 3 * 3 + y / 3][num] = true;
			grid[x][y] = num;

			bt(depth + 1);

			grid[x][y] = 0;
			rows[x][num] = false;
			cols[y][num] = false;
			grid3x3[x / 3 * 3 + y / 3][num] = false;
		}
	}
	else {
		bt(depth + 1);
	}
}

void solution() {
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j != n; j++) {
			grid[i][j] = s[j] - '0';
			if (grid[i][j] != 0) {
				rows[i][grid[i][j]] = true;
				cols[j][grid[i][j]] = true;
				grid3x3[i / 3 * 3 + j / 3][grid[i][j]] = true;
			}
		}
	}
	
	bt(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}