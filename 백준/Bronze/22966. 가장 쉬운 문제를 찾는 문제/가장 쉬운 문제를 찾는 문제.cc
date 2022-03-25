#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	int n;
	cin >> n;
	map<int, string> dic;
	for (int i = 0; i != n; i++) {
		int num;
		string s;
		cin >> s >> num;
		dic[num] = s;
	}
	cout << dic.begin()->second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}