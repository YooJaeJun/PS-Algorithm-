#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j != m; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	vector<vector<int>> b(n, vector<int>(m));
	vector<vector<int>> ab(n, vector<int>(m));
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j != m; j++) {
			b[i][j] = s[j] - '0';
			ab[i][j] = (a[i][j] == b[i][j]);
		}
	}
	if (n < 3 || m < 3) {
		if (a == b) {
			cout << 0;
		}
		else {
			cout << -1;
		}
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (false == ab[i][j]) {	// a, b 다르면 뒤집기
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						ab[k][l] = ab[k][l] == 1 ? 0 : 1;
					}
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (false == ab[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}