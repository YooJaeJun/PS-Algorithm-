#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string strSum(string s1, string s2) {
	int siz = 0;
	if (s1.size() < s2.size()) {
		swap(s1, s2);	// s1을 큰 쪽으로
	}
	siz = s1.size();
	int coef = 0;
	string ans;
	for (int i = siz - 1; i >= 0; i--) {
		int x = 0;

		x = i >= s1.size() - s2.size() ?
			s1[i] - '0' + s2[i - (s1.size() - s2.size())] - '0' + coef :
			s1[i] - '0' + coef;

		ans = to_string(x % 10) + ans;

		x /= 10;
		if (x == 0) coef = 0;
		else coef = 1;
	}
	if (coef == 1) 
		ans = '1' + ans;

	return ans;
}

vector<vector<string>> memo;

string comb(long long n, long long m) {
	if (memo[n][m] != "") return memo[n][m];
	if (m == 1) return to_string(n);
	else if (m == 0 || n == m) return "1";
	memo[n][m] = strSum(comb(n - 1, m - 1), comb(n - 1, m));
	return memo[n][m];
}

void solution() {
	long long n, m;
	cin >> n >> m;
	memo.resize(n + 1);
	for (auto& elem : memo) {
		elem.resize(m + 1);
	}
	cout << comb(n, m);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}