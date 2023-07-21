#include <iostream>
#include <vector>
using namespace std;

void printStars(int n) {
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			bool isEmpty = false;
			for (int x = 1; x < n; x *= 3) {
				if ((i / x) % 3 == 1 && (j / x) % 3 == 1) {
					cout << ' ';
					isEmpty = true;
					break;
				}
			}
			if (isEmpty == false) {
				cout << '*';
			}
		}
		cout << '\n';
	}
}

void solution() {
	int n;
	cin >> n;
	printStars(n);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}