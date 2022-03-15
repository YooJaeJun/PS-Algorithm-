#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> v(t);
	int ans = 0;
	int tmp;
	for (int i = 0; i != t; i++) {
		cin >> tmp;
		for (int& elem : v) {
			if (elem == tmp) {
				ans++;
				break;
			}
		}
		v[i] = tmp;
	}
	cout << ans;
	return 0;
}