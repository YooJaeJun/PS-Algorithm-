#include <iostream>
#include <vector>
using namespace std;

int n, r, c;
int ans = 0;

void z(int x, int y, int size) {
	if (x == r && y == c) {
		cout << ans << '\n';
		return;
	}
	if (r >= x && r < x + size &&
		c >= y && c < y + size) {
		// 1,2,3,4분면 별 재귀
		z(x, y, size / 2);
		z(x, y + size / 2, size / 2);
		z(x + size / 2, y, size / 2);
		z(x + size / 2, y + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

void solution() {
	cin >> n >> r >> c;
	z(0, 0, 1 << n);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}