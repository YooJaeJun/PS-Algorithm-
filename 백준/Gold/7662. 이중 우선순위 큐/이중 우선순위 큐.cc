#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solution() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		map<int, int> dic;	// 최대값 top
		for (int i = 0; i != k; i++) {
			char c;	cin >> c;
			int n;	cin >> n;
			if (c == 'I') {
				dic[n]++;	// key가 정수 n
			}
			else if (c == 'D' && false == dic.empty()) {
				if (n == 1) {
					auto it = dic.end();
					--it;
					if (it->second == 1) {
						dic.erase(it);
					}
					else {
						it->second -= 1;
					}
				}
				else if (n == -1) {
					if (dic.begin()->second == 1) {
						dic.erase(dic.begin());
					}
					else {
						dic.begin()->second--;
					}
				}
			}
		}
		if (dic.empty()) { cout << "EMPTY" << '\n'; }
		else {
			auto it = dic.end();
			--it;
			cout << it->first << ' ' << dic.begin()->first << '\n'; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}