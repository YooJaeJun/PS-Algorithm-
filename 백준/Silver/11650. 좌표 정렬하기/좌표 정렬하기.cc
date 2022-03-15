#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i != n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v.push_back({ n1, n2 });
	}
	sort(v.begin(), v.end());
	
	for(auto& elem : v) {
		cout << elem.first << ' ' << elem.second << '\n';
	}
	return 0;
}