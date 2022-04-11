#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> lcs(s1.size() + 1, vector<int>(s2.size() + 1));

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << lcs[s1.size()][s2.size()] << '\n';

	string ans;
	for (int i = s1.size(), j = s2.size(); lcs[i][j] != 0; ) {
		if (i >= 1 && lcs[i][j] == lcs[i - 1][j]) {
			i--;
		}
		else if (j >= 1 && lcs[i][j] == lcs[i][j - 1]) {
			j--;
		}
		else {
			ans = s1[i - 1] + ans;
			i--;	
			j--;
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}