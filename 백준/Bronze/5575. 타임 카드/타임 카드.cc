#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct worktime {
	int h1;	int m1;	int s1;
	int h2;	int m2;	int s2;
};
int main() {
	worktime w[3];
	for (int i = 0; i != 3; i++) {
		cin >> w[i].h1 >> w[i].m1 >> w[i].s1 >> w[i].h2 >> w[i].m2 >> w[i].s2;
		int h = w[i].h2 - w[i].h1;
		int m = w[i].m2 - w[i].m1;
		int s = w[i].s2 - w[i].s1;
		if (s < 0) {
			s += 60;
			m--;
		}
		if (m < 0) {
			m += 60;
			h--;
		}
		printf("%d %d %d\n", h, m, s);
	}
	return 0;
}