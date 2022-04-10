#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll min1, max1;
vector<bool> isNono;

void nono() {
	for (ll i = 2; i * i <= max1; i++) {
		ll sq = i * i;
		ll coef = min1 / sq;
		if (coef * sq < min1) coef++;

		for (ll j = sq * coef; j <= max1; j += sq) {
			isNono[j - min1] = false;
		}
	}
}

void solution() {
	cin >> min1 >> max1;
	isNono.resize(max1 - min1 + 1, true);

	nono();

	int ans = 0;
	for (auto elem : isNono) {
		if (elem) ans++;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}