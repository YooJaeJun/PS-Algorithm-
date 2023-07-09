#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	int sum = 0;
	for (int i = 0; i != n; i++) {
		sum += v[i];
	}
	float average = (float)sum / n;
	cout << floor(average + 0.5) << '\n';	// round()는 -0 나옴

	sort(v.begin(), v.end());
	cout << v[n / 2] << '\n';

	// 최빈값, 개수 중복 시 두번째 큰 값 map으로 구해보기
	map<int, int> mp;
	for (int i = 0; i != n; i++) {
		mp[v[i]]++;
	}
	auto maxMap = max_element(mp.begin(), mp.end(),
		[](const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.second < p2.second; });

	int max = maxMap->second;
	int cnt = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (maxMap->second == it->second) {
			cnt++;
		}
		if (cnt == 2) {
			cout << it->first << '\n';
			break;
		}
	}
	if (cnt != 2) {
		cout << maxMap->first << '\n';
	}

	cout << v.back() - v.front() << '\n';

	return 0;
}