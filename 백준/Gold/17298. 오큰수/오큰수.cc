#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	stack<int> st;
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			ans[i] = -1;
		}
		while (1) {
			if (st.empty()) {
				ans[i] = -1;
				break;
			}
			if (v[i] < st.top()) {
				ans[i] = st.top();
				break;
			}
			else {
				st.pop();
			}
		}
		st.push(v[i]);
	}

	for (auto& elem : ans) {
		cout << elem << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}