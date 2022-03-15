#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		if (num == 0) { cout << "1 0" << '\n'; }
		else if (num == 1) { cout << "0 1" << '\n'; }
		else { 
			int sum = 1;
			vector<int> v(num);
			v[0] = v[1] = 1;
			for (int i = 2; i < num; i++) {
				v[i] = v[i - 1] + v[i - 2];
			}
			cout << v[num - 2] << ' ' << v[num - 1] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}