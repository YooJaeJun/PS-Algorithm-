#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}

bool ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (cross(x1, y1, x2, y2, x3, y3) * cross(x1, y1, x2, y2, x4, y4) <= 0 &&
		cross(x3, y3, x4, y4, x1, y1) * cross(x3, y3, x4, y4, x2, y2) <= 0) {

		// 다 0일 때, 만나지 않는 평행인지 판단
		if (min(x1, x2) > max(x3, x4) ||
			min(y1, y2) > max(y3, y4) ||
			min(x3, x4) > max(x1, x2) ||
			min(y3, y4) > max(y1, y2)) {
			return false;
		}

		return true;
	}
	return false;
}

bool contain(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	return min(x1, x2) > min(x3, x4) && max(x1, x2) < max(x3, x4) &&
		min(y1, y2) > min(y3, y4) && max(y1, y2) < max(y3, y4);
}

void solution() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;	// 선분

	ll x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x3 >> y3 >> x4 >> y4;
	x5 = x3;	y5 = y4;
	x6 = x4;	y6 = y3;

	
	if (ccw(x1, y1, x2, y2, x3, y3, x5, y5) || ccw(x1, y1, x2, y2, x3, y3, x6, y6) ||
		ccw(x1, y1, x2, y2, x4, y4, x5, y5) || ccw(x1, y1, x2, y2, x4, y4, x6, y6) ||
		contain(x1, y1, x2, y2, x3, y3, x4, y4)) {
		cout << "T" << '\n';
	}
	else {
		cout << "F" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}