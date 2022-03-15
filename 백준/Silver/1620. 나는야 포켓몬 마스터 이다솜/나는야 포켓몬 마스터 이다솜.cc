#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;



void solution() {
	int n, m;
	cin >> n >> m;
	map<int, string> mp1;
	map<string, int> mp2;
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		mp1[i] = s;
		mp2[s] = i;
	}
	string quest;
	for (int i = 0; i != m; i++) {
		cin >> quest;
		bool isIdx = false;
		if ((quest.front() >= '0' && quest.front() <= '9') ||
			(quest.back() >= '0' && quest.back() <= '9')) {
			cout << mp1[stoi(quest) - 1] << '\n';
		}
		else {
			cout << mp2[quest] + 1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}