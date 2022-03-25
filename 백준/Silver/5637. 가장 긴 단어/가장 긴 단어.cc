#include <iostream>
#include <vector>
using namespace std;


void solution() {
	string s;
	int maxSize = 0;
	string ans;
	while (1) {
		cin >> s;
		if (s == "E-N-D") {
			break;
		}
		
		int i = 0;
		while(i < s.size()) {
			if ((s[i] >= 'a' && s[i] <= 'z') ||
				s[i] == '-') {
				i++;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {	// 소문자로 저장
				s[i] -= ('A' - 'a');
				i++;
			}
			else {
				s.erase(s.begin() + i);
			}
		}

		if (maxSize < (int)s.size()) {
			maxSize = (int)s.size();
			ans = s;
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}