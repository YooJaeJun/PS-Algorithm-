#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}

bool ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	return cross(x1, y1, x2, y2, x3, y3) * cross(x1, y1, x2, y2, x4, y4) < 0;
}

void solution() {
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	cout << ccw(x1, y1, x2, y2, x3, y3, x4, y4);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}