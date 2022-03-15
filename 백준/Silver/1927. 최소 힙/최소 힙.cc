#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solution() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i != n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) { 
				cout << 0 << '\n'; 
			}
			else { 
				cout << pq.top() << '\n'; 
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}