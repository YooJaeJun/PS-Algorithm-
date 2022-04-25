#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(10, 1);
int cnt = 1;

void init() {
	cnt++;
	for (auto& elem : v) {
		elem++;
	}
}

void solution() {
	string s;
	cin >> s;
	for (int i = 0; i != s.size(); i++) {
		int num = s[i] - '0';
		if (v[num]) {
			v[num]--;
		}
		else if (num == 9) {
			if (v[6]) {
				v[6]--;
			}
			else {
				init();
				v[num]--;
			}
		}
		else if (num == 6) {
			if (v[9]) {
				v[9]--;
			}
			else {
				init();
				v[num]--;
			}
		}
		else {
			init();
			v[num]--;
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}