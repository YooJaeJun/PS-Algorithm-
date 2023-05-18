#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, ans;	

enum eOperator {
	eplus, eminus, emultiple, edivision
};

void bt(int depth, vector<int>& oper, int result) {	// +,-,x,/ 수
	if (depth == n) {
		ans.push_back(result);
		return;
	}

	for (int i = 0; i != 4; i++) {
		if (oper[i] <= 0) continue;

		--oper[i];
		switch (i)
		{
		case eplus:
			bt(depth + 1, oper, result + arr[depth]);
			break;
		case eminus:
			bt(depth + 1, oper, result - arr[depth]);
			break;
		case emultiple:
			bt(depth + 1, oper, result * arr[depth]);
			break;
		case edivision:
			bt(depth + 1, oper, result / arr[depth]);
			break;
		}

		++oper[i];
	}
}

void solution() {
	cin >> n;
	arr.resize(n);

	for (int i = 0; i != n; i++) {
		cin >> arr[i];
	}
	vector<int> oper(4);
	for (int i = 0; i != 4; i++) {
		cin >> oper[i];
	}
	
	bt(1, oper, arr[0]);
	
	cout << *max_element(ans.begin(), ans.end()) << '\n' << *min_element(ans.begin(), ans.end());
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}