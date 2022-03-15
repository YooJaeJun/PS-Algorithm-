#include <iostream>
#include <vector>
using namespace std;

const long long inf = 999999999;
void solution() {
	int n, s;
	cin >> n >> s;
	vector<int> v(n + 1);
	vector<long long> sum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (i > 1) { sum[i] = sum[i - 1] + v[i]; }
		else { sum[1] = v[1]; }
	}
	int ans = inf;
	int idx = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = idx; j <= n; j++) {
			if (sum[j] - sum[i] >= s) {
				ans = ans > j - i ? j - i : ans;
				idx = j;
				break;
			}
		}
	}
	if (ans == inf) { cout << 0; }
	else { cout << ans; }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}