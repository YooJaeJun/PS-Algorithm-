#include <iostream>
#include <vector>
using namespace std;

void solution() {
	bool once = false;
	for (int i = 1; i <= 10; i++) {
		int n;
		cin >> n;
		if (n % 5 == 0) {
			once = true;
			cout << n;
			break;
		}
	}
	if (once == false) { cout << 0; }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}