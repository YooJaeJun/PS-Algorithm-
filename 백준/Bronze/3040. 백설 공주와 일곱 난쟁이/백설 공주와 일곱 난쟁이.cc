#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int sum = 0;
	for (int i = 0; i != 9; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	
	for (int i = 0; i != 9; i++) {
		for (int j = 0; j != 9; j++) {
			if (sum - v[i] - v[j] == 100) {
				for (int k = 0; k != 9; k++) {
					if (k != i && k != j) {
						cout << v[k] << endl;
					}
				}
				return 0;
			}
		}
	}
	return 0;
}