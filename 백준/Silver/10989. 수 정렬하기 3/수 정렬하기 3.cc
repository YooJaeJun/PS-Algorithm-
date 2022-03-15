#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(10001);
	for (int i = 0; i != n; i++) {
		int num;
		cin >> num;
		v[num]++;
	}

	for (int i = 0; i != v.size(); i++) {
		while (v[i]--) {
			cout << i << '\n';
		}
	}

	return 0;
}