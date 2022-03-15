#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	queue<int> ans;
	for (int i = 1; false == q.empty(); i++) {
		if (i % k == 0) {
			ans.push(q.front());
		}
		else {
			q.push(q.front());
		}
		q.pop();
	}

	cout << "<";
	while (false == ans.empty()) {
		cout << ans.front();
		ans.pop();
		if (ans.size() != 0) {
			cout << ", ";
		}
	}
	cout << ">";
	return 0;
}