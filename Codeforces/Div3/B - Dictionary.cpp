#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

void solution() {
	string s;
	cin >> s;
	int ans = 1 + (s[0] - 'a') * 25;
	ans += s[0] < s[1] ? s[1] - 'a' - 1 : s[1] - 'a';
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}