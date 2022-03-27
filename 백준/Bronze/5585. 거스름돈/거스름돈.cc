#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int ans = 0;
int x = 0;

bool check(int coin) {
	ans += x / coin;
	x %= coin;
	if (x == 0) {
		return true;
	}
	return false;
}

void solution() {
	int n;
	cin >> n;
	x = 1000 - n;
	if (check(500)) { cout << ans; return; }
	if (check(100)) { cout << ans; return; }
	if (check(50)) { cout << ans; return; }
	if (check(10)) { cout << ans; return; }
	if (check(5)) { cout << ans; return; }
	if (check(1)) { cout << ans; return; }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}