#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	vector<int> v = { h - y, w - x, y - 0, x - 0 };
	cout << *min_element(v.begin(), v.end());
	return 0;
}