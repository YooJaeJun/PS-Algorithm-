#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		while (num--) {
			cout << '=';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}