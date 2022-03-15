#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans = 0;
	int idx;
	while(true) {
		if (s1.find(s2) != string::npos) {
			idx = s1.find(s2);
			for (int i = 0; i != idx + s2.size(); i++) {
				s1.erase(s1.begin());
			}
			ans++;
		}
		else {
			cout << ans;
			break;
		}
	}
	return 0;
}