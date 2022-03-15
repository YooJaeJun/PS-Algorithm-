#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		vector<int> v(h * w + 1);
		int num = 101;
		int w_ = 0;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				v[(i - 1) * h + j] = num;
				num += 100;
			}
			num = 101;
			num += ++w_;
		}
		printf("%d\n", v[n]);
	}

	return 0;
}
