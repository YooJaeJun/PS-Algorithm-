#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int sum = 0;
	for (int i = 0; i != 4; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum / 60 << '\n' << sum % 60;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}