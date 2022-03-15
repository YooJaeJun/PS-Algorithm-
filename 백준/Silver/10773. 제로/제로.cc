#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solution() {
	stack<int> st;
	int k;
	cin >> k;
	for (int i = 0; i != k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			st.pop();	// 0: no empty 보장 가능
		}
		else {
			st.push(num);
		}
	}
	int sum = 0;
	while (st.empty() == false) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}