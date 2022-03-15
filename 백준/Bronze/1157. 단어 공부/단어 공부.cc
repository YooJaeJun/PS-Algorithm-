#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v(26, 0);
	for (const auto& elem : s) {
		if (elem >= 'a') {
			v[elem - 'a']++;
		}
		else {
			v[elem - 'A']++;
		}
	}
	int max = 0;
	int idx = 0;
	bool overlap = false;
	for (int i = 0; i != v.size(); i++) {
		if (max < v[i]) {
			max = v[i];
			idx = i;
			overlap = false;
		}
		else if (max == v[i]) {
			overlap = true;
		}
	}
	if (overlap) {
		cout << "?";
	}
	else {
		printf("%c", idx + 'A');
	}
	return 0;
}