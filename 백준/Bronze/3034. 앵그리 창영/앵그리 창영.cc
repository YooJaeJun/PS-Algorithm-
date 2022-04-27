#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int diag(int w, int h) {
	return sqrt(w * w + h * h);
}

void solution() {
	int n, w, h;
	cin >> n >> w >> h;
	
	for (int i = 0; i != n; i++) {
		int num;
		cin >> num;
		int limit = max(w, h);
		limit = max(limit, diag(w, h));

		if (num <= limit) cout << "DA" << '\n';
		else cout << "NE" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}