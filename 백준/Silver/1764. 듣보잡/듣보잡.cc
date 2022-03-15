#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	int n, m;
	cin >> n >> m;
	map<string, int> dic;
	for (int i = 0; i != n; i++) {
		string str;
		cin >> str;
		dic[str]++;
	}
	for (int i = 0; i != m; i++) {
		string str;
		cin >> str;
		dic[str]++;
	}

	vector<string> ans;
	for (auto& elem : dic) {
		if (elem.second >= 2) {
			ans.push_back(elem.first);
		}
	}
	cout << ans.size() << '\n';
	for (auto& elem : ans) {
		cout << elem << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}