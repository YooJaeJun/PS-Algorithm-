#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << '<';
	while (false == q.empty()) {
		for (int i = 0; i != k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (false == q.empty()) {
			cout << ", ";
		}
		else {
			cout << '>';
		}
	}

	return 0;
}