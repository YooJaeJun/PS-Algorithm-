#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	int n;
	cin >> n;
	map<string, int> dic;
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		dic[s]++;
	}

	auto it = dic.begin();
	if (dic.size() == 1 && dic.begin()->second == 2) {
		cout << "NO" << '\n';
		return;
	}

	while (it != --dic.end()) {
		string s1 = it++->first;
		string s2 = it->first;
		int minSize = min(s1.size(), s2.size());
		bool isSame = true;
		for (int i = 0; i != minSize; i++) {
			if (s1[i] != s2[i]) {
				isSame = false;
				break;
			}
		}
		if (isSame) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}