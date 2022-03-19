#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int zeroCnt = 0, minusOneCnt = 0, oneCnt = 0;

void plusCnt(int num) {
	switch (num) {
	case -1:
		minusOneCnt++;	break;
	case 0:
		zeroCnt++;	break;
	case 1:
		oneCnt++;	break;
	}
}

void div(int x, int y, int size) {
	if (size == 1) {
		plusCnt(v[x][y]);
		return;
	}

	int num = v[x][y];
	bool possible = true;
	for (int i = x; i != x + size; i++) {
		for (int j = y; j != y + size; j++) {
			if (num != v[i][j]) {
				possible = false;
			}
		}
	}

	if (possible == false) {
		for (int i = 0; i < size; i += size / 3) {
			for (int j = 0; j < size; j += size / 3) {
				div(x + i, y + j, size / 3);
			}
		}
	}
	else {
		plusCnt(num);
	}

}

void solution() {
	int n;
	cin >> n;
	v.resize(n);
	for (auto& elem : v) {
		elem.resize(n);
	}
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			cin >> v[i][j];
		}
	}

	div(0, 0, n);
	cout << minusOneCnt << '\n' << zeroCnt << '\n' << oneCnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}