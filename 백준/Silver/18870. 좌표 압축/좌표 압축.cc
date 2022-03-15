#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> originV(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
		originV[i] = v[i];
	}
	sort(v.begin(), v.end());
	map<int, int> mp;
	int cnt = 1;
	mp[v[0]] = 0;
	for (int i = 1; i != n; i++) {
		if (v[i] != v[i - 1]) {
			mp[v[i]] = cnt++;
		}
	}
	for (int i = 0; i != n; i++) {
		cout << mp[originV[i]] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}