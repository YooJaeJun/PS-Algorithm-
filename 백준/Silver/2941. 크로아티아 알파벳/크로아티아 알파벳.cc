#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int ch_check(const string& s) {
	int cnt = 0;
	for (int i = 0; i != s.size(); i++) {
		if (s[i] == 'c' && i + 1 < s.size()) {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				cnt++;	i++;
				continue;
			}
		}
		else if (s[i] == 'd' && i + 1 < s.size()) {
			if (s[i + 1] == '-') {
				cnt++;	i++;
				continue;
			}
			else if (i + 2 < s.size() && s[i + 1] == 'z' && s[i + 2] == '=') {
				cnt++;	i += 2;
				continue;
			}
		}
		else if (s[i] == 'l' && i + 1 < s.size()) {
			if (s[i + 1] == 'j') {
				cnt++;	i++;
				continue;
			}
		}
		else if (s[i] == 'n' && i + 1 < s.size()) {
			if (s[i + 1] == 'j') {
				cnt++;	i++;
				continue;
			}
		}
		else if (s[i] == 'n' && i + 1 < s.size()) {
			if (s[i + 1] == 'j') {
				cnt++;	i++;
				continue;
			}
		}
		else if (s[i] == 's' && i + 1 < s.size()) {
			if (s[i + 1] == '=') {
				cnt++;	i++;
				continue;
			}
		}
		else if (s[i] == 'z' && i + 1 < s.size()) {
			if (s[i + 1] == '=') {
				cnt++;	i++;
				continue;
			}
		}
		cnt++;
	}
	return cnt;
}

int main() {
	string s;
	cin >> s;
	cout << ch_check(s);
	return 0;
}