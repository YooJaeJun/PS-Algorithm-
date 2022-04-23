#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool contain(int cx, int cy, int r, int x, int y) {
	return (cx - x) * (cx - x) + (cy - y) * (cy - y) < r * r;
}

void solution() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 0; i != n; i++) {
		int cx, cy, r;
		cin >> cx >> cy >> r;
		bool cont1 = contain(cx, cy, r, x1, y1);
		bool cont2 = contain(cx, cy, r, x2, y2);

		if ((cont1 && false == cont2) || 
			false == cont1 && cont2) {
			ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}