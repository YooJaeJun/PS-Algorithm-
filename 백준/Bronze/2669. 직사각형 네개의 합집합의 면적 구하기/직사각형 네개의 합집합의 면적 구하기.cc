#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> v(101, vector<int>(101, 0));
	
	int lbx, lby, rtx, rty;
	for (int i = 0; i != 4; i++) {
		cin >> lbx >> lby >> rtx >> rty;
		for (int j = lby; j < rty; j++) {
			for (int k = lbx; k < rtx; k++) {
				v[j][k] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i != 101; i++) {
		for (int j = 0; j != 101; j++) {
			if (v[i][j]) { ans++; }
		}
	}
	cout << ans;
	return 0;
}