#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

void solution() {
	int n;
	cin >> n;
	stack<ll> st;
	ll ans = 0;

	for (int i = 0; i != n; i++) {
		ll num;
		cin >> num;
		while (st.empty() == false) {
			if (st.top() <= num) {
				st.pop();
			}
			else {
				break;
			}
		}
		ans += st.size();
		st.push(num);
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