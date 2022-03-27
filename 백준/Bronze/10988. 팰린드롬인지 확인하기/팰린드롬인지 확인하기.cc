#include <iostream>
#include <vector>
using namespace std;

void solution() {
	string s;
	cin >> s;
	for (int i = 0; i != s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			cout << 0;
			return;
		}
	}
	cout << 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}