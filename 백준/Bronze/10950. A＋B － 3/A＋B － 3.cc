#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B, total;
	cin >> total;
	vector<int> sum;
	for (int i = 0; i != total; i++) {
		cin >> A;
		cin >> B;
		sum.push_back(A + B);
	}
	for (int i = 0; i != total; i++) {
		cout << sum[i] << endl;
	}

	return 0;
}