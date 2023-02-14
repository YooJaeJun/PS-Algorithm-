#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;
vector<string> strs = { "aa", "aaa", "bb", "bbb" };
bool ans = false;

void recur(int idx) {
	if (idx >= s.size()) {
		ans = true;
		return;
	}

	for (int i = 0; i != 4; i++) {
		if (strs[i] == s.substr(idx, 2)) {
			recur(idx + 2);
		}
		if (strs[i] == s.substr(idx, 3)) {
			recur(idx + 3);
		}
		if (ans) return;
	}
}

void solution() {
	cin >> s;
	ans = false;
	recur(0);
	if (ans) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}