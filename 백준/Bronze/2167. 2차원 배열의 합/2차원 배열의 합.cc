#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vv(n, vector<int>(m));
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			cin >> vv[i][j];
		}
	}
	int k;
	cin >> k;
	for (int a = 0; a != k; a++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		i--;	
		j--;	
		x--;	
		y--;
		int sum = 0;
		for (int b = i; b <= x; b++) {
			for (int c = j; c <= y; c++) {
				sum += vv[b][c];
			}
		}
		cout << sum << endl;
	}
}