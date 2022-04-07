#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> nums;
string signs;

void split(string s) {
	string tmp;
	for (int i = 0; i != s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			signs += s[i];
			nums.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}
	nums.push_back(stoi(tmp));
}

void solution() {
	string s;
	cin >> s;
	split(s);

	// - 부터 다음 - 나온 곳까지
	int sum = 0;
	bool minusState = false;
	int idx = 1;
	for (int i = 0; i != signs.size(); i++) {
		if (signs[i] == '-') {
			minusState = true;
		}
		if (minusState) {
			signs[i] = '-';
		}
	}
	
	int ans = nums[0];
	for (int i = 0; i != signs.size(); i++) {
		if (signs[i] == '+') {
			ans += nums[i + 1];
		}
		else {
			ans -= nums[i + 1];
		}
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