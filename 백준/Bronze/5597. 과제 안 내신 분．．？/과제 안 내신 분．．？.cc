#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	map<int, int> dic;
	for (int i = 1; i <= 28; i++) {
		int key;
		cin >> key;
		dic[key] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (dic[i] == 0) {
			cout << i << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}