#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nodes(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
	}

	stack<int> st;	// idx
	int ans = 0;
	st.push(0);
	
	for (int i = 1; i <= n + 1; i++) {
		while (st.empty() == false &&
			nodes[i] < nodes[st.top()]) {

			int h = nodes[st.top()];
			st.pop();
			int v = i - st.top() - 1;
			ans = max(ans, h * v);
		}
		st.push(i);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}