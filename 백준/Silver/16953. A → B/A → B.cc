#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int a, b;
int inf = 999999999;
int minimum = inf;

void dfs(long long x, int cnt) {
	if (x == b) {
		minimum = min(minimum, cnt);
	}

	if (x * 2 > 0 && x * 2 <= b) {
		dfs(x * 2, cnt + 1);
	}

	string strX = to_string(x);
	strX += '1';
	long long nx = stoll(strX);
	if (nx > 0 && nx <= (long long)b) {
		dfs(nx, cnt + 1);
	}
}

void solution() {
	cin >> a >> b;
	dfs(a, 0);

	if (minimum != inf) {
		cout << minimum + 1;
	}
	else {
		cout << -1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}