#include <iostream>
#include <vector>
using namespace std;

void solution() {
	string s;
	cin >> s;
	int sum = 10;
	for (int i = 1; i < s.size(); i++) {
		sum = s[i - 1] == s[i] ? sum + 5 : sum + 10;
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}