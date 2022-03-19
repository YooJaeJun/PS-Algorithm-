#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() == s2.size()) {
		int cnt = 0;
		for (int i = 0; i != s1.size(); i++) {
			cnt += s1[i] != s2[i];
		}
		cout << cnt;
		return;
	}
	
	const int inf = 99999999;
	int cnt = 0, ans = inf;
	int size = s2.size() - s1.size();
	int idx = 0;
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j != s1.size(); j++) {
			cnt += s1[j] != s2[j + i];
		}
		ans = min(ans, cnt);
		cnt = 0;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}