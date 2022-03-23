#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct coords {
	int x, y;
};
void solution() {
	map<int, int> dicX, dicY;
	for (int i = 0; i != 3; i++) {
		int x, y;
		cin >> x >> y;
		dicX[x]++;
		dicY[y]++;
	}
	int idx = 0;
	for (auto& elem : dicX) {
		if (elem.second == 1) {
			cout << elem.first << ' ';
		}
	}
	for (auto& elem : dicY) {
		if (elem.second == 1) {
			cout << elem.first << ' ';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}