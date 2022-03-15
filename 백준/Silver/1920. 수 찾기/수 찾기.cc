#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i != n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	int m;
	scanf("%d", &m);
	for (int i = 0; i != m; i++) {
		int num;
		scanf("%d", &num);
		int start = 0;
		int end = a.size() - 1;
		int middle;
		bool found = false;
		while(start <= end) {
			middle = (start + end) / 2;
			if (num == a[middle]) {
				found = true;
				break;
			}
			else if (num > a[middle]) {
				start = middle + 1;
			}
			else {
				end = middle - 1;
			}
		}
		printf("%d\n", found);
	}

	return 0;
}