#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;

void solution() {
	int n;
	cin >> n;
	vector<ll> nodes(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
	}

	stack<ll> st;	// idxs
	st.push(0);
	ll ans = 0;

	for (int i = 1; i <= n + 1; i++) {
		while (st.empty() == false &&
			nodes[i] < nodes[st.top()]) {
			
			ll h = nodes[st.top()];
			st.pop();
			ll v = i - st.top() - 1;
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