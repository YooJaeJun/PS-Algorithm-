#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i != t; i++) {
		int a, b;
		cin >> a >> b;
		vector<int> muls;
		string first;
		int coef = a;
		a = 1;
		for (int i = 0; i != b; i++) {
			a *= coef; 
			a %= 10;
			if (a == 0) {
				a = 10;
			}
			auto it = find(muls.begin(), muls.end(), a);
			if (it == muls.end()) {
				muls.push_back(a);
			}
			else {
				break;
			}
		}
		int idx = (b - 1) % muls.size();
		cout << muls[idx] << endl;
	} 
}