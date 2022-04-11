#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<string> vs1, vs2;
	const int coef = 3;		// 컴파일러마다 2 or 3 byte

	for (int i = 0; i != s1.size(); i += coef) {
		vs1.push_back(s1.substr(i, coef));
	}
	for (int i = 0; i != s2.size(); i += coef) {
		vs2.push_back(s2.substr(i, coef));
	}

	vector<vector<int>> lcs(vs1.size() + 1, vector<int>(vs2.size() + 1));
	for (int i = 1; i <= vs1.size(); i++) {
		for (int j = 1; j <= vs2.size(); j++) {
			if (vs1[i - 1] == vs2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	cout << lcs[vs1.size()][vs2.size()];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}