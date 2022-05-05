#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct line {
	int x1, y1, x2, y2;
};

vi building;
vector<line> lines;
int ans = 0;

double ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}

bool intersect(line a, line b) {
	return ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1) * ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2) <= 0 &&
		ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1) * ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2) <= 0;
}

bool compareLine(line& curLine, int start, int cur) {
	while(start != cur - 1 && start != cur + 1) {
		// 사이에 있는 줄들 검사
		if (start < cur) cur--;
		else cur++;
		if (intersect(curLine, lines[cur])) {
			return false;
		}
	}
	return true;
}

void solution() {
	int n;
	cin >> n;
	building = vi(n);
	for (int i = 0; i != n; i++) {
		cin >> building[i];
		lines.push_back({ i, 0, i, building[i] });
	}

	// 빌딩 순회
	for (int start = 0; start != n; start++) {
		int cnt = 0;
		// 인접 빌딩은 항상 ++
		if (start != 0) cnt++;
		if (start != n - 1) cnt++;

		// 빌딩 간 선 잇고 교차 확인
		for (int cur = start - 2; cur >= 0; cur--) {
			line curLine = { start, building[start], cur, building[cur] };
			if (compareLine(curLine, start, cur)) cnt++;
		}
		for (int cur = start + 2; cur < n; cur++) {
			line curLine = { start, building[start], cur, building[cur] };
			if (compareLine(curLine, start, cur)) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}