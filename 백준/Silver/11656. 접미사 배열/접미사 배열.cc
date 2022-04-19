#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	string s;
	cin >> s;
	vector<string> v;
	string tmp;
	for (int i = s.size() - 1; i >= 0; i--) {
		tmp = s[i] + tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (auto& elem : v) {
		cout << elem << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}