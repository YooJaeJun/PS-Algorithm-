#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	std::map<int, int> m;
	vector<int> idxs(t);
	int val;
	for (int& elem : idxs) {
		cin >> elem >> val;
		m[elem] = val;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
	return 0;
}