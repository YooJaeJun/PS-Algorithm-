#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	int r, c;
	cin >> r >> c;
	vector<string> v(r);
	for (int i = 0; i != r; i++) {
		cin >> v[i];
	}

	map<int, int> rank;
	int num = 1;
	for (int i = c - 2; i > 0; i--) {
		bool isRanked = false;
		for (int j = 0; j != r; j++) {
			if (v[j][i] != '.') {
				if (rank[v[j][i] - '0'] == 0) {
					rank[v[j][i] - '0'] = num;
					isRanked = true;
				}
			}
		}
		if (isRanked) {
			num++;
		}
	}

	for (int i = 1; i <= 9; i++) {
		cout << rank[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}