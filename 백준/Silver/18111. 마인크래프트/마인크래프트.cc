#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<int> v(n * m);
	for (int i = 0; i != n * m; i++) {
		cin >> v[i];
	}

	vector<pair<int, int>> ret;
	int originB = b;
	vector<int> originV(n * m);
	for (int i = 0; i != n * m; i++) {
		originV[i] = v[i];
	}

	for (int x = 0; x <= 256; x++) {
		int time = 0;
		b = originB;
		for (int i = 0; i != n * m; i++) {
			v[i] = originV[i];
		}

		for (auto& elem : v) {
			if (elem < x) {
				b -= (x - elem);
				time += (x - elem);
				elem = x;
			}
			else if (elem > x) {
				b += (elem - x);
				time += (elem - x) * 2;
				elem = x;
			}
		}
		if (b >= 0) {
			ret.push_back({ time, x });
		}
	}
	sort(ret.begin(), ret.end());
	pair<int, int> ans = ret[0];
	for (int i = 0; i < ret.size() - 1; i++) {
		if (ret[i].first == ret[i + 1].first &&
			ret[i].second < ret[i + 1].second) {
			ans = ret[i + 1];
		}
		else {
			break;
		}
	}
	cout << ans.first << ' ' << ans.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}