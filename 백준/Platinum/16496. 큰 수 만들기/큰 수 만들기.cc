#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(int n1, int n2) {
	string s1 = to_string(n1) + to_string(n2);
	string s2 = to_string(n2) + to_string(n1);
	return s1 > s2;
}

void solution() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i != n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), compare);

	while (arr[0] == 0) {
		if (arr.size() == 1) break;
		arr.erase(arr.begin());
	}

	for (auto& elem : arr) {
		cout << elem;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}