#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

void solution() {
	// 부분합 나머지 연산 이용
	int n, m;
	cin >> n >> m;
	vector<ll> pSum(n);
	map<ll, ll> mp;
	for (int i = 0; i != n; i++) {
		ll num;
		cin >> num;
		pSum[i] += num;
		if (i - 1 >= 0) { pSum[i] += pSum[i - 1]; }
		pSum[i] %= m;
		mp[pSum[i]]++;	// 나머지 같은 값 세주기
	}

	ll ans = mp[0];	// 나머지 0이면 바로 세주기
	for (auto& elem : mp) {
		// 나머지가 같은 수 중 2개 선택(nC2)해서 부분합 시 나누어 떨어지는 알고리즘
		ans += elem.second * (elem.second - 1) / 2;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}