#include <iostream>
#include <vector>
using namespace std;

void solution() {
	string s;
	cin >> s;
	for (auto& ch : s) {
		if (ch >= 'A' && ch <= 'Z') {
			cout << ch;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}