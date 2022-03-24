#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int ans = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			char ch;
			cin >> ch;

			if ((i % 2 == 1 && j % 2 == 1) ||
				(i % 2 == 0 && j % 2 == 0)) {
				ans = ch == 'F' ? ans + 1 : ans;
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}