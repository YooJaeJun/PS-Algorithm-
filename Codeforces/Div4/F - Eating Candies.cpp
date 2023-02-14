#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	int ans = 0, cur = 0;
	int sum1 = v[0], sum2 = v.back();
	int i = 0, j = v.size() - 1;
	bool iMove = false, jMove = false;
	while (i < j) {
		if (iMove) sum1 += v[i];
		if (jMove) sum2 += v[j];

		iMove = false;
		jMove = false;

		if (sum1 == sum2) {
			cur += 2;
			ans = cur;
			i++;
			j--;
			iMove = true;
			jMove = true;
		}
		else if (sum1 > sum2) {
			j--;
			cur++;
			jMove = true;
		}
		else {
			i++;
			cur++;
			iMove = true;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}