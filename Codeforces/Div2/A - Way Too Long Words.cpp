#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution() {
	int n;
	cin >> n;
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		if (s.size() <= 10) {
			cout << s << '\n';
			continue;
		}

		string ans = s[0] + to_string(s.size() - 2) + s.back();
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}