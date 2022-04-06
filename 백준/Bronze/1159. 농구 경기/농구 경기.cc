#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	int n;
	cin >> n;
	string s;
	map<char, int> dic;
	for (int i = 0; i != n; i++) {
		cin >> s;
		dic[s[0]]++;
	}
	string ans;
	for (auto& elem : dic) {
		if (elem.second >= 5) {
			ans += elem.first;
		}
	}
	if (ans == "") cout << "PREDAJA";
	else cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}