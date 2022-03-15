#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solution() {
	int m;
	cin >> m;
	map<int, int> dic;
	for (int i = 0; i != m; i++) {
		string s;
		cin >> s;
		int n;
		if (s == "add") {
			cin >> n;
			dic[n] = 1;
		}
		else if (s == "remove") {
			cin >> n;
			dic[n] = 0;
		}
		else if (s == "check") {
			cin >> n;
			cout << dic[n] << '\n';
		}
		else if (s == "toggle") {
			cin >> n;
			if (dic[n] == 1) { dic[n] = 0; }
			else if (dic[n] == 0) { dic[n] = 1; }
		}
		else if (s == "all") {
			for (auto& elem : dic) {
				elem.second = 0;
			}
			for (int i = 1; i <= 20; i++) {
				dic[i] = 1;
			}
		}
		else if (s == "empty") {
			for (auto& elem : dic) {
				elem.second = 0;
			}
			dic.clear();
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}