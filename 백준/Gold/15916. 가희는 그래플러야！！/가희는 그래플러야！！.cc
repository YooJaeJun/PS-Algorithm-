#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll ret = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}

bool ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	return cross(x1, y1, x2, y2, x3, y3) * cross(x1, y1, x2, y2, x4, y4) <= 0 &&
		cross(x3, y3, x4, y4, x1, y1) * cross(x3, y3, x4, y4, x2, y2) <= 0;
}

void solution() {
	ll n;
	cin >> n;
	vector<ll> arr(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll k;
	cin >> k;

	if (arr[1] == k) {
		cout << "T";
		return;
	}

	ll x1 = 0;
	ll y1 = 0;
	ll x2 = 100000;
	ll y2 = 100000 * k;

	for (ll i = 2; i <= n; i++) {
		ll x3 = i - 1;
		ll y3 = arr[i - 1];
		ll x4 = i;
		ll y4 = arr[i];

		if (ccw(x1, y1, x2, y2, x3, y3, x4, y4)) {
			cout << "T";
			return;
		}
	}
	cout << "F";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}