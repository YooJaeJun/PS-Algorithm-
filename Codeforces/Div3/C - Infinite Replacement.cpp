#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

long long sqr(int siz) {
	long long ret = 1;
	for (int i = 0; i != siz; i++) {
		ret *= 2;
	}
	return ret;
}

void solution() {
	string s, t;
	cin >> s >> t;

	if (t == "a") {
		cout << 1 << '\n';
	}
	else if (t.find('a') != string::npos) {
		cout << -1 << '\n';
	}
	else {
		cout << sqr(s.size()) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}