#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	vector<int> v(9);
	for (int i = 0; i != 9; i++) {
		cin >> v[i];
	}
	vector<int> ans;
	// 진짜 무차별
	for (int a = 0; a != 9; a++) {
		for (int b = a + 1; b != 9; b++) {
			for (int c = b + 1; c != 9; c++) {
				for (int d = c + 1; d != 9; d++) {
					for (int e = d + 1; e != 9; e++) {
						for (int f = e + 1; f != 9; f++) {
							for (int g = f + 1; g != 9; g++) {
								if (v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + v[g] == 100) {
									ans.push_back(v[a]);
									ans.push_back(v[b]);
									ans.push_back(v[c]);
									ans.push_back(v[d]);
									ans.push_back(v[e]);
									ans.push_back(v[f]);
									ans.push_back(v[g]);

									sort(ans.begin(), ans.end());
									for (auto& elem : ans) {
										cout << elem << '\n';
									}
									return;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}