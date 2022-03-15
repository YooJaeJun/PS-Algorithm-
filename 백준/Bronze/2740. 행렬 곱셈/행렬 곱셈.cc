#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int y = 0; y != n; y++) {
		for (int x = 0; x != m; x++) {
			cin >> v[y][x];
		}
	}
	int n2, m2;
	cin >> n2 >> m2;
	vector<vector<int>> v2(n2, vector<int>(m2));
	for (int y = 0; y != n2; y++) {
		for (int x = 0; x != m2; x++) {
			cin >> v2[y][x];
		}
	}

	int sum = 0;
	if (m == n2) {
		for (int y = 0; y != n; y++) {
			for (int x = 0; x != m2; x++) {
				for (int k = 0; k != m; k++) {
					sum += v[y][k] * v2[k][x];
				}
				printf("%d ", sum);
				sum = 0;
			}
			printf("\n");
		}
	}
	return 0;
}