#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	int cnt = 0;
	for (int i = 0; i != t; i++) {
		string s;
		cin >> s;
		vector<char> v;
		v.push_back(s[0]);
		bool isgroup = true;
		for (int i = 1; i != s.size(); i++) {
			auto it = find(v.begin(), v.end(), s[i]);
			if (v.begin() != v.end() && it == v.end()) {
				v.push_back(s[i]);
			}
			else if (s[i - 1] != *it) {	//나왔던 건데 직전 문자와 다르면
				isgroup = false;
				break;
			}
		}
		if (isgroup) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}