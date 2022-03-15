#include <iostream>
using namespace std;

int main() {
	const int total = 8;
	int a[total];
	int sort = -1;

	for (int i = 0; i != total; i++) {
		cin >> a[i];
		if (a[i] == i + 1 && sort != 1 && sort != 2) {
			sort = 0;
		}
		else if (a[i] == total - i && sort != 0 && sort != 2) {
			sort = 1;
		}
		else {
			sort = 2;
		}
	}
	if (sort == 0) { cout << "ascending"; }
	else if (sort == 1) { cout << "descending"; }
	else { cout << "mixed"; }
	return 0;
}